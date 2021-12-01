char * makeGood(char * s){
    int top = 0;
    for (int i = 0; s[i]; i++) {
        /*当栈顶元素为空，或者栈顶元素与入栈元素大小符合标准的时候， 入栈*/
        if (top == 0 || abs(s[top - 1] - s[i]) != 'a' - 'A') {
            s[top++] = s[i];
        } else {
            top--;//不符合出栈
        }
    }
    s[top] = '\0';
    return s;
}