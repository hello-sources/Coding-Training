int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumCost(int* cost, int costSize){
    int ans = 0;
    qsort(cost, costSize, sizeof(int), cmp);
    if (costSize == 1) return cost[0];
    else if (costSize == 2 || (costSize == 3 && cost[2] <= cost[1])) return cost[0] + cost[1];
    else {
        for (int i = 1; i <= costSize; i++) {
            if (i % 3 == 1 || i % 3 == 2) ans += cost[i - 1];
        }
    } 
    return ans;
}