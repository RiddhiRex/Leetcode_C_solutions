//Solution 1
#include <stdio.h>
#include <string.h>
void rev(char *str) {
    int l = 0;
    int r = strlen(str)-1;
    while(l<r) {
        int t = str[l];
        str[l]=str[r];
        str[r]=t;
        l++;
        r--;
    } 
    printf("%s ", str);
}
int main() {
    char str[] = "helo";
    rev(str);
    printf("%s ", str);
    return 0;
}



//Solution 2
void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}
