//把字符串从后往前数，找到第一个为奇数的值就OK
char * largestOddNumber(char * num){
    int len = strlen(num) - 1;
    for (int i = len; i >= 0; i--) {
        if ((num[i] - '0') % 2 == 1) {
            num[i + 1] = '\0';
            return num;
        }
    }
    return "";
}