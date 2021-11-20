/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** buildArray(int* target, int targetSize, int n, int* returnSize){
    int i = 0, cnt = 1;
    char **ans = (char **)malloc(sizeof(char *) * (2 * n - 1));
    *returnSize = 0;
    while (i < targetSize && cnt <= n) {
        ans[(*returnSize)++] = "Push";
        if (target[i] == cnt) i++;
        else ans[(*returnSize)++] = "Pop";
        cnt++;
    }
    return ans;
}