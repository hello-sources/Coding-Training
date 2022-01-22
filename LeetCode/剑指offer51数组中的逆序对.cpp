/*************************暴力超时**********************************/
int reversePairs(int* nums, int numsSize){
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) ans++;
        }
    }
    return ans;
}

/***************************归并排序*************************/
int merge_sort(int left, int right, int *nums, int *temp) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int res = merge_sort(left, mid, nums, temp) + merge_sort(mid + 1, right, nums, temp);
    for (int k = left; k <= right; k++) {
        temp[k] = nums[k];
    }
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i == mid + 1) nums[k] = temp[j++];
        else if (j == right + 1 || temp[i] <= temp[j]) nums[k] = temp[i++];
        else {
            nums[k] = temp[j++];
            res += mid - i + 1;
        }
    }
    return res;
}

int reversePairs(int* nums, int numsSize){
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    return merge_sort(0, numsSize - 1, nums, temp);
}
