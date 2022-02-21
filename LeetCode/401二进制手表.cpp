/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int turnedOn, int* returnSize){
    char **res = (char **)malloc(sizeof(char *) * 12 * 60);
    *returnSize = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 60; j++) {
            if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                char *temp = (char *)malloc(sizeof(char) * 6);
                sprintf(temp, "%d:%02d", i, j);
                res[(*returnSize)++] = temp;
            }
        }
    }
    return res;
}