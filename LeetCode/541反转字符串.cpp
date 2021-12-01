//题目设置的有点难懂，就是每2k个一组，每一组反转前k个字符
//当一组不够2k个，但是大于等于k个的时候，也反转前k个
//否则如果一组不够k个，全部反转
char * reverseStr(char * s, int k){
    int len = strlen(s), flag;
    for (int i = 0; i < len; i += 2 * k) {
        flag = len - i < k ? len - i : k;
        for (int j = 0; j < flag / 2; j++) {
            char c = s[i + j];
            s[i + j] = s[i + flag - j - 1];
            s[i + flag - j - 1] = c;
        }
    }
    return s;
}