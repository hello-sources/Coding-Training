char * interpret(char * command){
    int len = strlen(command), top = 0;
    char *res = (char *)malloc(sizeof(char) * (len + 5));
    for (int i = 0; i < len; i++) {
        if (command[i] == 'G') res[top++] = command[i];
        if (command[i] == '(' && command[i + 1] == 'a') {
            res[top++] = 'a';
            res[top++] = 'l';
            i += 3;
        } else if (command[i] == '(' && command[i + 1] == ')') {
            res[top++] = 'o';
            i++;
        }
    }
    res[top] = '\0';
    return res;
}