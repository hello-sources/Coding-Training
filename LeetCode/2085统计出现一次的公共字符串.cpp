int countWords(char ** words1, int words1Size, char ** words2, int words2Size){
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < words1Size; i++) {
        int flag = 0;
        for (int j = 0; j < words1Size; j++) {
            if (strcmp(words1[i], words1[j]) == 0) {
                flag++;
            }
        }
        if (flag > 1) continue;
        for (int j = 0; j < words2Size; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                flag++;
            }
        }
        if (flag == 2) cnt1++;
    }
    return cnt1;
}