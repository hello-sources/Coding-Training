char * removeDuplicates(char * s){
    int len = strlen(s), top = 0;
    char *temp = (char *)malloc(sizeof(char) * (len + 1));
    temp[0] = '\0';
    for (int i = 0; i < len; i++) {
        if (top > 0 && temp[top - 1] == s[i]) {
            top--;
        } else {
            temp[top++] = s[i];
        }
    }
    temp[top] = '\0';
    return temp;
}