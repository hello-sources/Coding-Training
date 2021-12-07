int minOperations(char ** logs, int logsSize){
    int deeps = 0;
    char str[2][6] = {"../", "./"};
    for (int i = 0; i < logsSize; i++) {
        if (deeps > 0 && strcmp(logs[i], str[0]) == 0) deeps--;
        else if ((deeps <= 0 && strcmp(logs[i], str[0]) == 0) || strcmp(logs[i], str[1]) == 0) continue;
        else {
            deeps++;
        }
    }
    return deeps >= 0 ? deeps : 0;
}