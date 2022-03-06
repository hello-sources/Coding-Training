/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char * boxes, int* returnSize){
    int len = strlen(boxes);
    int *res = (int *)malloc(sizeof(int) * len);
    *returnSize = 0;
    for (int i = 0; i < len; i++) {
        int cnt = 0;
        for (int j = 0; j < len; j++) {
            if (i != j && boxes[j] == '1') cnt += fabs(i - j);  
        }
        res[(*returnSize)++] = cnt;
    }
    return res;
}