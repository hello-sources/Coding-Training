bool winnerOfGame(char * colors){
    int cntA = 0, cntB = 0, len = strlen(colors), cnt = 0;
    char ch = 'A';
    for (int i = 0; i < len; i++) {
        if (colors[i] != ch) {
            cnt = 1;
            ch = colors[i];
        } else {
            cnt++;
            if (cnt >= 3) {
                if (ch == 'A') cntA++;
                else cntB++;
            }
        }
    }
    return cntA > cntB;
}