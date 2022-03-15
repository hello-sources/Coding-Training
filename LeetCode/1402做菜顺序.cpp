int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize){
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
    int ans = 0, pre = 0;
    for (int i = 0; i < satisfactionSize; i++) {
        if (pre + satisfaction[i] > 0) {
            pre += satisfaction[i];
            ans += pre;
        }
    }
    return ans;
}