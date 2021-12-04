/***
 * 连续N个0，再连续N个1，则有N个子串符合要求。
 * 用now表示当前数字连续出现的次数，用last表示上一个数字连续出现的次数，
 * 设last=n,则now<=last时，now每增加1，符合要求的字串数目就增加1。
 * ***/

int countBinarySubstrings(char * s){
    int cnt = 0, len = strlen(s);
    int now = 0, last = 0, temp = s[0];
    for (int i = 0; i < len; i++) {
        if (temp == s[i]) {
            now++;
        } else {
            last = now;
            now = 1;
            temp = s[i];
        }
        if (now <= last) cnt++;
    }
    return cnt;
}