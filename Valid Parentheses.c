bool isValid(char* s) {
    int len = strlen(s);
    int stacklen = 0;
    int top = -1;
    char *stack = (char *)malloc(10000* sizeof(char));
    for(int i=0;i<len;i++) {
        if (s[i]=='{' || s[i]=='[' || s[i]=='(') {
            stack[++top]=s[i];
        }
        else {
            if (top==-1)
                return false;
            if(stack[top]!='{' && s[i]=='}')
                return false;
            if(stack[top]!='(' && s[i]==')')
                return false;
            if(stack[top]!='[' && s[i]==']')
                return false;
            top=top-1;
        }
    }
    if (top!=-1)
        return false;
    else
        return true;
}
