/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
    int *res = (int *)malloc(sizeof(int) * len);
    memset(res, 0, sizeof(int) * len);
    int *stack = (int*)malloc(len * sizeof(int));
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (top == -1 && seq[i] == '(') {
            res[i] = 0;
            stack[++top] = 0;
        } else if (top != -1 && seq[i] == '(') {
            int tmp = (stack[top] == 0) ? 1 : 0;
            res[i] = tmp;
            stack[++top] = tmp;
        } else if (top != -1 && seq[i] == ')') {
            res[i] = stack[top--];
        }
    }
    *returnSize = len;
    return res;
}

/*********************法2*********************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
    int *res = (int *)malloc(sizeof(int) * len);
    memset(res, 0, sizeof(int) * len);
    int dep = 0;
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') {
            dep++;
            res[i] = dep % 2;
        } else {
            res[i] = dep % 2;
            dep--;
        }
    }
    *returnSize = len;
    return res;
}