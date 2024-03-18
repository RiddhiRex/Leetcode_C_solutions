int dayOfYear(char* date) {
    char *s = strtok(date, "-");
    int year = atoi(s);
    s = strtok(NULL, "-");
    int month = atoi(s);
    s = strtok(NULL, "-");
    int days = atoi(s);
    int daysofmonth[] = {31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((year%4==0 && year%100!=0) || (year%400==0 && year%100==0)) {
        daysofmonth[1]=29;
    }
    for(int i=0;i<month-1;i++) {
        days+=daysofmonth[i];
    }
    return days;

}
