int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int cnt = 0;
    char res[3][10] = {"type", "color", "name"};
    for (int i = 0; i < 3; i++) {
        if (strcmp(res[i], ruleKey) == 0) {
            for (int j = 0; j < itemsSize; j++) {
                if (strcmp(items[j][i], ruleValue) == 0) cnt++;
            }
        }
    }
    return cnt;
}