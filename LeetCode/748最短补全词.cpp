char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    int num1[26] = {0};
    int num2[26] = {0};
    int ind, cnt = 16;
    char *res = (char *)malloc(sizeof(char) * 16);
    for (int i = 0; licensePlate[i]; i++) {
        if (licensePlate[i] <= 'z' && licensePlate[i] >= 'a') num1[licensePlate[i] - 'a']++;
        if (licensePlate[i] <= 'Z' && licensePlate[i] >= 'A') num1[licensePlate[i] - 'A']++;
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int k = 0; k < 26; k++) {
            num2[k] = num1[k];
        }
        int j = 0;
        for (; words[i][j]; j++) {
            num2[words[i][j] - 'a']--;
        }
        ind = j;
        for (int k = 0; k < 26; k++) {
            if (num2[k] > 0) {
                ind = 16; 
                break;
            }
        }
        if (ind < cnt) {
            res = words[i];
            cnt = ind;
        }
    }
    return res;
}