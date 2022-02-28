#define MAX_N 64
char * optimalDivision(int* nums, int numsSize){
    char *res = (char *)malloc(sizeof(char) * MAX_N);
    if (numsSize == 1) {
        sprintf(res, "%d", nums[0]);
        return res;
    }
    if (numsSize == 2) {
        sprintf(res, "%d/%d", nums[0], nums[1]);
        return res;
    }
    sprintf(res, "%d/(%d", nums[0], nums[1]);
    int pos = strlen(res);
    char str[5];
    for (int i = 2; i < numsSize; i++) {
        sprintf(str, "%d", nums[i]);
        sprintf(res + pos, "/%s", str);
        pos += strlen(str) + 1;
    }
    sprintf(res + pos, "%s", ")");
    return res;
}