#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/syscall.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {  // Child process
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) { //ptrace used to attach to another process and monitor the execution of another process.  
          //PTRACE_TRACEME will request the calling process to be traced. This is used by the child process before calling exec to allow its parent to trace it.
            perror("ptrace");
            return 1;
        }
       
        char *args[] = {"ls", NULL};
        execvp("ls", args); //execute any cmd
        perror("execvp");
        return 1;
    } else {  // Parent process
        int status;
        waitpid(pid, &status, 0);

        while (1) {
            ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
            waitpid(pid, &status, 0); //wait for the process to complete execution or wait for state change.

            if (WIFEXITED(status)) { //Checks if the process/child process exited normally or not. normally called after waitpid()
                break;
            }
        }
    }

    return 0;
}
