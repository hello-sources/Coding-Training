int findCenter(int** edges, int edgesSize, int* edgesColSize){
    int cnt[100010] = {0};
    for (int i = 0; i < edgesSize; i++) {
        cnt[edges[i][0]]++;
        cnt[edges[i][1]]++;
    }
    for (int i = 1; i <= edgesSize + 1; i++) {
        if (cnt[i] == edgesSize) return i;
    }
    return -1;
}