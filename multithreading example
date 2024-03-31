//C program with multithread: creation and synchronizing multiple threads.
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void* threadFunc(void* arg) {
    int threadID = *((int*)arg);
    printf("Thread %d: Hello, world! \n", threadID);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadIDs[i] = i + 1;
        int result = pthread_create(&threads[i], NULL, threadFunc, &threadIDs[i]);
        if (result != 0) {
            printf("Failed to create thread %dn", i + 1);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed. \n");

    return 0;
}
