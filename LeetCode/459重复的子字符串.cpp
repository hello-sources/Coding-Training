//枚举尽可能多的字符串，优化加速是使用一半的源字符串
//通过不断的枚举可能存在的子串长度，判断是否存在相关子串
bool repeatedSubstringPattern(char * s){
    int len = strlen(s);
    for (int i = 1; 2 * i <= len; i++) {
        if (len % i == 0) {
            int flag = 1;
            for (int j = i; j < len; j++) {
                if (s[j] != s[j - i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) return true;
        }
    }
    return false;
}