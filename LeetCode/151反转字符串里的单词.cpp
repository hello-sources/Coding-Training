char * reverseWords(char * s){
    int len = strlen(s);
    if (s <= 0) return s;
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    res[len] ='\0';
    char *stack = (char *)malloc(sizeof(char) * (len + 1));
    int top = 0, index = 0;
    for (int i = len - 1; i >= 0; i--) {
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') stack[top++] = s[i--];
        while (top > 0) res[index++] = stack[--top];
        res[index++] = ' ';
    }
    index--;
    while (index >= 0 && res[index] == ' ') index--;
    res[index + 1] = '\0';
    return res;
}