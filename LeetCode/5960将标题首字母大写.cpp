char * capitalizeTitle(char * title){
    int len = strlen(title), cnt = 0;
    for (int i = 0; i < len; i++) {
        if (title[i] >= 65 && title[i] <= 90) title[i] += 32; 
    }
    char *s = strtok(title, " ");
    char *res = (char *)malloc(sizeof(char) * 105);
    while (s) {
        if (strlen(s) > 2) {
            s[0] -= 32;
        } 
        for (int i = 0; i < strlen(s); i++) res[cnt++] = s[i];
        res[cnt++] = ' ';
        s = strtok(NULL, " ");
    }
    res[len] = '\0';
    return res;
}