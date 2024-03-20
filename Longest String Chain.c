int compare(const void *a, const void *b) {
    return (strlen(*(char **)a)-strlen(*(char **)b));


}
bool checkifprevword(char *w1, char *w2) {
    if (strlen(w1) != strlen(w2)+1)
        return false;
    int i=0;
    int j=0;
    int l1 = strlen(w1);
    int l2 = strlen(w2);
    while(i<l1 && j<l2) {
        if(w1[i]==w2[j])
            j++;
        i++;
    }
    return (j==l2);
}
int longestStrChain(char** words, int wordsSize) {
    qsort(words, wordsSize, sizeof(char *), compare);
    //int *dp = (int *)malloc(wordsSize * sizeof(int *));
    int dp[1000]={0};
    int maxlen = 0;
    for(int i=0;i<wordsSize;i++) {
        dp[i]=1;
        printf("%s ", words[i]);
        for (int j=0;j<i;j++) {
            if (checkifprevword(words[i], words[j])) {
                dp[i] = dp[i]>dp[j]? dp[i]:dp[j]+1;
            }
        }
        maxlen = (dp[i] > maxlen)? dp[i]:maxlen; 
    }
    return maxlen;
}
