char* intToRoman(int num) {
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *res = (char *)malloc(20*sizeof(char));
    res[0]='\0';
    int i=0;

    for(i=0;i<13;i++) {
        while(num>=vals[i]) {
            strcat(res, symbols[i]);
            num=num-vals[i];
        }
    }
    return res;

}
