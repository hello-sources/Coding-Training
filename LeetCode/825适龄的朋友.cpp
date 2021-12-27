int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int numFriendRequests(int* ages, int agesSize){
    qsort(ages, agesSize, sizeof(int), cmp);
    int left = 0, right = 0, ans = 0;
    for (int i = 0; i < agesSize; i++) {
        if (ages[i] <= 14) continue;
        while (ages[left] <= 0.5 * ages[i] + 7) left++;
        while (right + 1 < agesSize && ages[i] >= ages[right + 1]) right++;
        ans += right - left;
    }
    return ans;
}