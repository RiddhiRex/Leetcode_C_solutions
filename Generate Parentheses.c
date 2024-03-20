/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **ans;
int idx;

void generate(char *s, int open, int close, int n) {
    if(strlen(s)==2*n) {
        ans[++idx]=strdup(s);
        printf("%s \n", ans[idx]);
        return;
    }
    if(open<n) {
        strcat(s, "(");
        generate(s, open+1, close, n);
        s[strlen(s)-1]='\0';
    }
    if(close<open) {
        strcat(s, ")");
        generate(s, open, close+1, n);
        s[strlen(s)-1]='\0';
    }
    return;
}
char** generateParenthesis(int n, int* returnSize) {
    ans = (char **)malloc(2000 *sizeof(char *));
    idx = -1;
    char curr_wrd[(2*n)+1];
    curr_wrd[0] = '\0';
    generate(curr_wrd,0,0,n);
    
    *returnSize = idx+1;
    return ans;
    
}
