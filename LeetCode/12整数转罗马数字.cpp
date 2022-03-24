int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char *ch[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char * intToRoman(int num){
    char *res = (char *)malloc(sizeof(char) * 20);
    res[0] = '\0';
    for (int i = 0; i < 13; i++) {
        while (num >= nums[i]) {
            num -= nums[i];
            strcpy(res + strlen(res), ch[i]);
        }
        if (num == 0) break;
    }
    return res;
}