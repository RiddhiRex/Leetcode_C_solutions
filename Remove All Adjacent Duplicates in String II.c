struct Node {
    int val;
    int cnt;
};
char* removeDuplicates(char* s, int k) {
    struct Node *stack = (struct node *)malloc(strlen(s)*sizeof(struct Node));
    int top=-1, i=0, j=0;
    for(i=0;i<strlen(s);i++) {
        if(top==-1 || stack[top].val!=s[i]) {
            top++;
            stack[top].val = s[i];
            stack[top].cnt = 1;
        } else {
            stack[top].cnt+=1;
            if (stack[top].cnt==k)
                top-=1;
        }
    }
    char *res = (char *)malloc((strlen(s)+1)*sizeof(char));
    int idx = 0;
    for(i=0;i<=top;i++) {
        for(j=0;j<stack[i].cnt;j++) {
           res[idx]=stack[i].val;
           idx++;
        }
    }
    res[idx]='\0';
    return res;
}
