#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* mystrtok(char* s, char d)
{
    // Stores the state of string
    static char* input = NULL;
 
    // Initialize the input string
    if (s != NULL)
        input = s;
 
    // Case for final token
    if (input == NULL)
        return NULL;
 
    // Stores the extracted string
    char* result = (char *)malloc(strlen(input)+1);
    int i = 0;
 
    // Start extracting string and
    // store it in array
    for (; input[i] != '\0'; i++) {
 
        // If delimiter is not reached
        // then add the current character
        // to result[i]
        if (input[i] != d)
            result[i] = input[i];
 
        // Else store the string formed
        else {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }
 
    // Case when loop ends
    result[i] = '\0';
    input = NULL;
       // Return the resultant pointer
    // to the string
    return result;
}
 
// Driver Code
int main()
{
    // Given string str
    char str[20] = "hello word";
 
    // Tokenized the first string
    char* ptr = mystrtok(str, ' ');
 
    // Print current tokenized string
    printf("%s ", ptr);
 
    // While ptr is not NULL
    while (ptr != NULL) {
        // Tokenize the string
        ptr = mystrtok(NULL, ' ');
 
        // Print the string
        printf(" --%s -- ", ptr);
    }
    return 0;
}
