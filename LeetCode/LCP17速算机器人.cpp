int calculate(char* s){
    int len = strlen(s);
    int x = 1, y = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            x = 2 * x + y;
        } else if (s[i] == 'B') {
            y = 2 * y + x;
        }
    }
    return x + y;
}