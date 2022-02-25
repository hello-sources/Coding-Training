void reverse(char *s, int start, int end) {
    int mid = (start + end) / 2;
    for (int i = 0; i < mid; i++) {
        char ch = s[i];
        s[i] = s[end - i - 1];
        s[end - i - 1] = ch;
    }
    return ;
}

void reverseWords(char* s, int sSize){
    int left = 0, right = 0;
    while (left < sSize && right < sSize) {
        while (right < sSize && s[right] != ' ') right++;
        reverse(s + left, 0, right - left);
        right++;
        left = right;
    }
    reverse(s, 0, sSize);
    return ;
}