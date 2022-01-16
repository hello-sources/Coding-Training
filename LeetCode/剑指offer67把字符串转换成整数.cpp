int strToInt(char* str){
    int num = 0, flag = 1, i = 0, max = INT_MAX / 10, ret = INT_MAX % 10;
    while (str[i] == ' ') i++;
    if (str[i] == '-') flag = -1, i++;
    else if (str[i] == '+') flag = 1, i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') break;
        if (num > max || (num == max && (str[i] - '0') > ret)) return flag == 1 ? INT_MAX : INT_MIN;
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num * flag;
}