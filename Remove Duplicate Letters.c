char* removeDuplicateLetters(char* s) {
    char seen[26]={0};
    int len=strlen(s), i, idx=0;
    for(i=0;i<len;i++) {
        if(seen[s[i]-'a']==0) {
            seen[s[i]-'a']=1;
            s[idx]=s[i];
            idx++;
        }
    }
    s[idx]='\0';
    return s;
}
