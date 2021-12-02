/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int line = 1, cnt = 0;
    int *ans = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; s[i]; i++) {
        if (cnt + widths[s[i] - 'a'] <= 100) {
            cnt += widths[s[i] - 'a'];
        } else {
            line++;
            cnt = 0;
            cnt += widths[s[i] - 'a'];
        }
    }
    ans[0] = line;
    ans[1] = cnt;
    *returnSize = 2;
    return ans;
}