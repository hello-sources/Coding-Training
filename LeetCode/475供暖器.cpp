/**
 * 为了使每个房屋都能供暖，对于每个房屋应该选择最近的取暖器为房屋供暖
 * 最近供暖器和房屋的距离即为最小加热半径
 * 所有房屋所需的最小加热半径的最大值即为可以覆盖房屋的最小加热半径
 * 注意取暖器的位置是乱序的，因此需要将取暖器排序
 * **/

int binary_search(int *nums, int size, int target) {
    int l = 0, r = size - 1;
    if (nums[l] > target) return -1;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (nums[mid] > target) r = mid - 1;
        else l = mid;
    }
    return l;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    int ans = 0;
    qsort(heaters, heatersSize, sizeof(int), cmp);
    for (int i = 0; i < housesSize; i++) {
        int k = binary_search(heaters, heatersSize, houses[i]);
        int j = k + 1;
        int ldis = (k < 0 ? INT_MAX : houses[i] - heaters[k]);
        int rdis = (j >= heatersSize ? INT_MAX : heaters[j] - houses[i]);
        int len = fmin(ldis, rdis);
        ans = fmax(ans, len);
    }
    return ans;
}