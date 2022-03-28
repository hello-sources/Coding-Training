int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x){
    //qsort(staple, stapleSize, sizeof(int), cmp);
    qsort(drinks, drinksSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < stapleSize; i++) {
        int left = 0, right = drinksSize - 1, target = x - staple[i];
        //if (target <= 0) continue;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (drinks[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        ans += left;
        ans %= 1000000007;
    }
    return ans;
}

/************************双指针**************************/
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x){
    qsort(staple, stapleSize, sizeof(int), cmp);
    qsort(drinks, drinksSize, sizeof(int), cmp);
    int ans = 0;
    int i = 0, j = drinksSize - 1;
    while (i < stapleSize && j >= 0) {
        int sum = staple[i] + drinks[j];
        if (sum <= x) {
            i++;
            ans += j + 1;
            ans %= 1000000007;
        } else j--;
    }
    return ans;
}