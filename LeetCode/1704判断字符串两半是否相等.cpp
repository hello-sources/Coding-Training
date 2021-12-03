bool halvesAreAlike(char * s){
    char *str = "aeiouAEIOU";
    int len = strlen(s);
    int cntl = 0, cntr = 0;
    for (int i = 0; s[i]; i++) {
        if (2 * i < len && strchr(str, s[i]) != NULL) cntl++;
        else if (strchr(str, s[i]) != NULL) cntr++;
    }
    return cntl == cntr;
}