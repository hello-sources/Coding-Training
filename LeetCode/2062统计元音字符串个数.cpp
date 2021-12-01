//首先得统计所有的子串，然后判断字串中是否存在'a''e''i''o''u'这五种元音
//使用或运算确定是否全部包含元音
int calc(char *word, int i, int j) {
    int flag = 1, mask = 0;
    for (int k = i; k <= j; k++) {
        if (word[k] == 'a') {
            mask |= 1;
        } else if (word[k] == 'e') {
            mask |= 2;
        } else if (word[k] == 'i') {
            mask |= 4;
        } else if (word[k] == 'o') {
            mask |= 8;
        } else if (word[k] == 'u') {
            mask |= 16;
        } else {
            flag = 0;
            break;
        }
    }
    return (mask == 31) && (flag == 1);
}

int countVowelSubstrings(char * word){
    int len = strlen(word), ans = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            ans += calc(word, i, j);
        }
    }
    return ans;
}