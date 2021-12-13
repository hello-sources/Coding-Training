int find(int *fa, int x) {
    if (fa[x] != x) {
        fa[x] = find(fa, fa[x]);
    }
    return fa[x];
}

void merge(int *fa, int a, int b) {
    fa[find(fa, a)] = find(fa, b);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int father[isConnectedSize];
    for (int i = 0; i < isConnectedSize; i++) {
        father[i] = i;
    }
    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = i + 1; j < isConnectedSize; j++) {
            if (isConnected[i][j] == 1) {
                merge(father, i, j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (father[i] == i) cnt++;
    }
    return cnt;
}