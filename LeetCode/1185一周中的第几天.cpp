char * dayOfTheWeek(int day, int month, int year){
    char *week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    if (((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) && month > 3) months[1] += 1;
    for (int i = 0; i < month - 1; i++) day += months[i];
    day += 365 * (year - 1971) + (year - 1969) / 4;
    return week[(day + 3) % 7];
}