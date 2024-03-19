bool validateIpv4(char *ip) {
    char *token = strtok(ip, ".");
    int part = 1;
    while(token) {
        if(strlen(token)==0 || strlen(token)>3)
            return false;
        if(token[0]=='0' && strlen(token)>1)
            return false;
        for(int i=0;i<strlen(token);i++) {
            if(isdigit(token[i])==false) 
                return false;
        }
        int n = atoi(token);
        if((part==1 && n==0) || n<0 || n>255 )
            return false;
        part++;
        token = strtok(NULL, ".");

    }
    if(part!=5)
        return false;
    return true;
}
bool validateIpv6(char *ip) {
    char *token = strtok(ip, ":");
    int part=1;
    while(token) {
        printf("%s | ", token);
        if (strlen(token)==0 || strlen(token)>4)
            return false;
        for(int i=0;i<strlen(token);i++) {
            if(!isxdigit(token[i]))
                return false;
        }
        part++;
        token = strtok(NULL, ":");
    }
    printf("%d ", part);
    if(part!=9)
        return false;
    return true;
}
char* validIPAddress(char* queryIP) {
    if(validateIpv4(queryIP))
        return "IPv4";
    else if(validateIpv6(queryIP))
        return "IPv6";
    else
        return "Neither";


}
