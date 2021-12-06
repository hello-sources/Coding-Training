#define SIZE 12

int calc_days(char *date) {
    int day_Month[SIZE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, day, month, flag, cnt = 0;
    year = (date[0] - '0') * 1000 + (date[1] - '0')*100 + (date[2] - '0')*10 + date[3] - '0';
    month = (date[5] - '0')*10 + date[6] - '0';
    day = (date[8] - '0')*10 + date[9] - '0';
    month--;
    cnt = day;
    while (year > 1970) {
        flag = 0;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            flag = 1;
        }
        while (month) {
            if (month == 2 && flag) cnt += 1, flag = 0;
            cnt += day_Month[--month];
        }
        year--;
        month = 12;
    }
    return cnt;
}


int daysBetweenDates(char * date1, char * date2){
    int cnt1 = calc_days(date1), cnt2 = calc_days(date2);
    return fabs(cnt1 - cnt2);
}


/***使用Zeller公式计算日期
 * 提示Zeller公式只适合于1582年10月15日之后的情形，功能是给一个日期计算星期几
 * 公式是W = [C/4] - 2C + y + [y/4] + [13 * (M+1） / 5] + d - 1，其中C等于世纪 - 1
 * 使用蔡勒公式与1600年1月1日进行比较得到的天数相减即可
 * 还有一个优化策略是为了避免每年都要处理闰年判断二月天数，设计使每年三月作为起始月
 * 计算得到年月差，加上中间闰年数目即可
 * ***/

int toDay(char *dateStr) {
    int year, month, day;
    sscanf(dateStr, "%d-%d-%d", &year, &month, &day);
    if (month <= 2) {
        year--;
        month += 10;
    } else month -= 2;
    return 365 * year + year / 4 - year / 100 + year / 400 + 30 * month + (3 * month - 1) / 5 + day - 584418;
}

int daysBetweenDates(char * date1, char * date2){
    return abs(toDay(date1) - toDay(date2));
}
