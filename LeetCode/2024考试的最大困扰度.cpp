int get_len(char *answerKey, int k, char ch) {
    int len = strlen(answerKey);
    int l = 0, cnt = 0, ans = 0;
    for (int i = 0; i < len; i++) {
        if (answerKey[i] == ch) cnt++;
        while (cnt > k) {
            if (answerKey[l] == ch) cnt--;
            l++;
        }
        ans = fmax(ans, i - l + 1);
    }
    return ans;
}

int maxConsecutiveAnswers(char * answerKey, int k){
    return fmax(get_len(answerKey, k, 'T'), get_len(answerKey, k, 'F'));
}