C program to implement strcat:
char * func(char *dest, char *src) {
    char *ptr = dest;
    while(*ptr!='\0')
        ptr++;
    while(*src!='\0') {
        *ptr=*src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}
int main()
{
   char st1[10]="asdf";
   char st2[]="qwer";
   func(st1, st2);
   printf("%s", st1);
    return 1;
}
