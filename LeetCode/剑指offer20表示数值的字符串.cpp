bool isNumber(char* s){
    int len = strlen(s), ind = 0;
    bool hasNUM = false, hasE = false, hasSign = false, hasDot = false;
    while (s[ind] == ' ') ind++;
    while (s[ind]) {
        while (s[ind] >= '0' && s[ind] <= '9') {
            ind++;
            hasNUM = true;
        }
        if (ind == len) break;
        char ch = s[ind];
        if (ch == 'e' || ch == 'E') {
            if (hasE || !hasNUM) return false;
            hasE = true;
            hasDot = hasNUM = hasSign = false;
        } else if (ch == '-' || ch == '+') {
            if (hasNUM || hasSign || hasDot) return false;
            hasSign = true;
        } else if (ch == '.') {
            if (hasDot || hasE) return false;
            hasDot = true;
        } else if (ch == ' ') break;
        else return false;
        ind++;
    }
    while (ind < len && s[ind] == ' ') ind++;
    return hasNUM && ind == len;
}