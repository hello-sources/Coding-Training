int maxNumberOfBalloons(char * text){
    int num[26] = {0};
    char temp[5] = "balon";
    for (int i = 0; text[i]; i++) {
        if (strchr(text, text[i]) != NULL) num[text[i] - 'a']++;
    }
    int min = 0;
    min = num[0] > num[1] ? num[1] : num[0];
    min = min > (num[11] / 2) ? (num[11] / 2) : min;
    min = min > (num[14] / 2) ? (num[14] / 2) : min;
    min = min > num[13] ? num[13] : min;
    return min;
}