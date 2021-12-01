//巧妙的使用第一个字符串重复两次，比较第二个字符串在不在生成的新串中
bool isFlipedString(char* s1, char* s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 != len2) return false;
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    int i = 0;
    for (; i < 2 * len1; i++) {
        temp[i] = s1[i % len1];
    }
    temp[i] = '\0';
    if (strstr(temp, s2) != NULL) return true;
    return false;
}