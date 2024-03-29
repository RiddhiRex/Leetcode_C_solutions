/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **result = (char **)malloc(n*sizeof(char *));
    *returnSize = n;
    for(int i=1;i<=n;i++) {
        result[i-1]=(char *)malloc(9*sizeof(char));
        if(i%3==0 && i%5==0)
            strcpy(result[i-1],"FizzBuzz");
        else if(i%3==0)
            strcpy(result[i-1],"Fizz");
        else if(i%5==0)
            strcpy(result[i-1],"Buzz");
        else
            sprintf(result[i-1], "%d", i);
    }
    return result;
}
