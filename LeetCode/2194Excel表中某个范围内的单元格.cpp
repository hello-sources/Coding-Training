/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** cellsInRange(char * s, int* returnSize){
    char **res = (char **)malloc(sizeof(char *) * 300);
    *returnSize = 0;
    for (int i = 0; i < 300; i++) {
        res[i] = (char *)malloc(sizeof(char) * 5);
    }
    for (char ch = s[0]; ch <= s[3]; ch++) {
        for (int i = s[1] - '0'; i <= s[4] - '0'; i++) {
            res[*returnSize][0] = ch;
            res[*returnSize][1] = i + '0';
            res[(*returnSize)++][2] = '\0';
        }
    }
    return res;
}