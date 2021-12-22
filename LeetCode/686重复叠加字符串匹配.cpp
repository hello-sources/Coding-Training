/**************strstr与strcat的使用***********/
int repeatedStringMatch(char * a, char * b){
    int lena = strlen(a), lenb = strlen(b);
    int max = lenb / lena + 2;
    char *str = (char *)malloc(sizeof(char) * (max * lena + 5));
    memset(str, 0, sizeof(str));
    for (int i = 0; i < max; i++) {
        strcat(str, a);
        char *temp = NULL;
        if (strlen(str) >= lenb) {
            temp = strstr(str, b);
        }
        if (temp != NULL) return i + 1;
    }
    return -1;
}