bool isPalindrome(char* s) {
    int len = strlen(s);
    int l=0;
    int r=len-1;
    while(l<r) {
        while(l<r && !isalnum(s[l])) {
            l+=1;
        }
        while(l<r && !isalnum(s[r])) {
            r-=1;
        }
        if(tolower(s[l])!=tolower(s[r]))
            return false;
        l+=1;
        r-=1;
    }
    return true;
}
