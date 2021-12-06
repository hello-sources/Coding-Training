bool checkIfPangram(char * sentence){
    int num[26] = {0};
    for (int i = 0; sentence[i]; i++) {
        num[sentence[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (num[i] == 0) return false;
    }
    return true;
}