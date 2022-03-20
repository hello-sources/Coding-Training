int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxCoins(int* piles, int pilesSize){
    qsort(piles, pilesSize, sizeof(int), cmp);
    int ans = 0, cnt = pilesSize / 3, ind = pilesSize - 2;
    for (int i = 0; i < cnt; i++) {
        ans += piles[ind];
        ind -= 2;
    }
    return ans;
}