int dayOfYear(char * date){
    int year, month, day, flag = 0, cnt = 0;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) flag = 1;
    for (int i = 0; i < month - 1; i++) {
        cnt += months[i];
    }
    if (month > 2) cnt += flag;
    cnt += day;
    return cnt;
}