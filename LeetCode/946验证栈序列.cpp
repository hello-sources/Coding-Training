bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int *stack = (int *)malloc(sizeof(int) * pushedSize);
    int top = -1, index = 0;
    for (int i = 0; i < pushedSize; i++) {
        stack[++top] = pushed[i];
        while (top != -1 && stack[top] == popped[index]) {
            top--;
            index++;
        }
    }
    if (top == -1) return true;
    return false;
}