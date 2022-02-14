int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumOperations(int* nums, int numsSize){
    if (numsSize == 1) return 0; 
    int ans = 0, cnt = 0;
    int temp[100005] = {0};
    int temp1[100005] = {0};
    for (int i = 0; i < numsSize && i + 2 < numsSize; i += 2) {
        temp[nums[i]]++;
        cnt++;
    }
    qsort(temp, cnt, sizeof(int), cmp);
    for (int i = 0; i < numsSize && i + 2 < numsSize; i += 2) {
        if (nums[i] != temp[0]) ans++;
    }
    cnt = 0;
    for (int i = 1; i < numsSize && i + 2 < numsSize; i += 2) {
        temp1[nums[i]]++;
        cnt++;
    }
    qsort(temp1, cnt, sizeof(int), cmp);
    int ind = (temp[0] == temp1[0] ? temp1[1] : temp1[0]);
    for (int i = 1; i < numsSize && i + 2 < numsSize; i += 2) {
        if (nums[i] != ind) ans++;
    } 
    return ans;
} 