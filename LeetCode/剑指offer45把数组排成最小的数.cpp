int cmp(const void *a, const void *b) {
    char num1[24], num2[24];
    sprintf(num1, "%d%d", *(int *)a, *(int *)b);
    sprintf(num2, "%d%d", *(int *)b, *(int *)a);
    return strcmp(num1, num2);
}

char* minNumber(int* nums, int numsSize){
    char *res = (char *)malloc(sizeof(char) * 1200);
    char *p = res;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        p += sprintf(p, "%d", nums[i]);
    }
    *p = '\0';
    return res;
}