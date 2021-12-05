int uniqueMorseRepresentations(char ** words, int wordsSize){
    char code[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char res[100][100];
    int cnt = 0, flag = 0;
    for (int i = 0; i < wordsSize; i++) {
        char temp[60] = {0};
        for (int j = 0; j < strlen(words[i]); j++) {
            strcat(temp, code[words[i][j] - 'a']);
        }
        for (int k = 0; k < cnt; k++) {
            if (strcmp(temp, res[k]) == 0) {
                flag++;
                break;
            }
        }
        if (flag == 0) {
            strcpy(res[cnt], temp);
            cnt++;
        }
        flag = 0;
    }
    return cnt;
}