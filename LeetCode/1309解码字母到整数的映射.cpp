char * freqAlphabets(char * s){
    //  造孽不好好看题目
    // char code[26][3] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10#", "11#", "12#", "13#", "14#", "15#", "16#", "17#", "18#", "19#", "20#", "21#", "22#", "23#", "24#", "25#", "26#"};
    int len = strlen(s), cnt = 0;
    char *res = (char *)calloc(len, sizeof(char));
    for (int i = 0; i < len; ) {
        if (i + 2 < len && s[i + 2] == '#') {
            res[cnt++] = ((s[i] - '0') * 10 + s[i + 1] - '1') + 'a';
            i += 3;
        } else {
            res[cnt++] = (s[i] - '1') + 'a';
            i++;
        }
    }
    res[cnt] = '\0';
    return res;
}