char * reorderSpaces(char * text){
    int len = strlen(text);
    int cntspace = 0, cntword = 0, need = 0, left = 0, cnt = 0;
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    if (text[0] != ' ') cntword++;
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') cntspace++;
        else if (i != 0 && text[i - 1] == ' ') cntword++;
    }
    if (cntword == 1) left = cntspace;
    else {
        need = cntspace / (cntword - 1);
        left = cntspace - need * (cntword - 1);
    }
    int count = cntword;
    for (int i = 0; i < len; i++) {
        if (text[i] != ' ') res[cnt++] = text[i];
        else if (i != 0 && text[i - 1] != ' ') {
            if (count > 1) {
                for (int k = 0; k < need; k++) {
                    res[cnt++] = ' ';
                }
                count--;
            }
        }
    }
    if (count == 1) {
        for (int k = 0; k < left; k++) {
            res[cnt++] = ' ';
        }
    }
    res[cnt] = '\0';
    return res;
}