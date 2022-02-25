int calculateTime(char * keyboard, char * word){
    int dis = 0, ind = 0;
    for (int i = 0; i < strlen(word); i++) {
        for (int j = 0; j < 26; j++) {
            if (keyboard[j] == word[i]) {
                dis += fabs(j - ind);
                ind = j;
                break;
            }
        }
    }
    return dis;
}