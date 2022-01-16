int myAtoi(char * s){
    int i = 0, num = 0, flag = 1, max = INT_MAX / 10, ret = INT_MAX % 10;
    while (s[i] == ' ') i++;
    if (s[i] == '-') flag = -1, i++;
    else if (s[i] == '+') flag = 1, i++;
    while (s[i]) {
        if (s[i] < '0' || s[i] > '9') break;
        if (num > max || (num == max && (s[i] - '0') > ret)) return flag == 1 ? INT_MAX : INT_MIN;
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * flag;
}