int cmp(int **a, int **b) {
    return (*b)[1] - (*a)[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    qsort(boxTypes, boxTypesSize, sizeof(int *), cmp);
    int ans = 0, ind = 0;
    for (int i = 0; i < boxTypesSize; i++) {
        int cnt = boxTypes[i][0];
        int size = boxTypes[i][1];
        while (ind < truckSize && cnt > 0) {
            ans += size;
            cnt--;
            ind++;
        }
        if (ind == truckSize) break;
    }
    return ans;
}