char * reformatDate(char * date){
    char *res = (char *)malloc(sizeof(char) * 15);
    char *temp = (char *)calloc(10, sizeof(char));
    char Month[13][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    temp = strtok(date, " ");
    while (temp) {
        int len = strlen(temp);
        if (temp[len - 1] <= 'z' && temp[len - 1] >= 'a' && temp[len - 3] <= '9' && temp[len - 3] >= '0') {
            if (len == 3) {
                res[8] = '0', res[9] = temp[0];
            } else {
                res[8] = temp[0], res[9] = temp[1];
            }
        } else if (temp[len - 3] <= 'Z' && temp[len - 3] >= 'A') {
            for (int i = 0; i < 12; i++) {
                if (strcmp(Month[i], temp) == 0) {
                    if (i < 9) res[5] = '0', res[6] = i + 1 + '0';
                    else res[5] = (i + 1) / 10 + '0', res[6] = (i + 1) % 10 + '0';
                }
            }
        } else {
            for (int i = 0; i < len; i++) {
                res[i] = temp[i];
            }
        }
        temp = strtok(NULL, " ");
    }
    res[4] = '-';
    res[7] = '-';
    free(temp);
    res[10] = '\0';
    return res;
}

//巧用sscanf与sprintf
#define MAX_LEN 11
#define MONTH 12

char month[MONTH][4] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

char *reformatDate(char *date)
{
    char day[5] = { 0 };
    char year[5] = { 0 };
    char month_temp[4] = { 0 };
    int imonth;
    char *ans = (char*)malloc(sizeof(char) * MAX_LEN);
    sscanf(date, "%[0-9]%*[a-z] %s %s", day, month_temp, year);
    for (int i = 0; i < MONTH; i++) {
        if (strcmp(month_temp, &month[i]) == 0) {
            imonth = i + 1;
        }
    }
    sprintf(ans, "%s-%02d-%02d", year, imonth, atoi(day));
    return ans;
}