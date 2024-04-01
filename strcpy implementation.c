
#include <stdio.h>

char * strcopy(char *d, char *s) {
    int i=0;
    while(s[i]!='\0') {
        d[i] = s[i];
        i+=1;
    }
    d[i]='\0';
    printf("%s ", d);
    return d;
}

int main()
{
char s[]="asdf";
char d[10];
strcopy(d, s);
}
