int maxDepth(char * s){
    int len = strlen(s), cnt = 0, top = -1, ans = 0;
    char *stack = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            ++top;
            stack[top] = s[i];
            ans = fmax(ans, top + 1);
        } else if (s[i] == ')') {
            top--;
        }
    }
    free(stack);
    return ans;
}