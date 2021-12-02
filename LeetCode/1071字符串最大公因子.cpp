//strcmp, strcpy, strcat
char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    char *temp1 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    char *temp2 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(temp1, str1);
    strcat(temp1, str2);
    strcpy(temp2, str2);
    strcat(temp2, str1);
    if (strcmp(temp1, temp2) != 0) return "";
    int num = len1 % len2;
    while (num) {
        len1 = len2;
        len2 = num;
        num = len1 % len2;
    }
    char *res = (char *)malloc(sizeof(char) * (len2 + 1));
    for (int i = 0; i < len2; i++) {
        res[i] = str1[i];
    }
    res[len2] = '\0';
    free(temp1);
    free(temp2);
    return res;
}