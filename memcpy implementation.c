//C program to implement memcpy:
 void memcopy(void *b, const void *a, int len) {
    char *ip = (char *)a;
    char *op = (char *)b;
    if(b == NULL || a == NULL) {
        return;
    }
    for(int i=0; i<len ;i++) {
        op[i]=ip[i];
    }
}
int main()
{
    char a[] = "abcdef";
    char b[10];
    memset(b, 0, 10);
    printf("a:%s\t b:%s\n",a,b);

    memcopy(b, a , strlen(a));
    printf("a:%s\t b:%s\n",a,b);
    return 0;
}

