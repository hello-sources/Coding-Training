int find(int *fa, int x) {
    return fa[x] == x ? fa[x] : find(fa, fa[x]);
}

void merge(int *fa, int x, int y) {
    int fx = find(fa, x), fy = find(fa, y);
    if (fx == fy) return ;
    if (fx < fy) fa[fy] = fx;
    else fa[fx] = fy;
}

int cmp(const void *a, const void *b) {
    return  (*(int **)a)[0] - (*(int **)b)[0];
} 

int earliestAcq(int** logs, int logsSize, int* logsColSize, int n){
    int *fa = (int *)malloc(sizeof(int) * n);
    int *times = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        times[i] = -1;
    }
    qsort(logs, logsSize, sizeof(int *), cmp);
    for (int i = 0; i < logsSize; i++) {
        int x = logs[i][1], y = logs[i][2];
        int fx = find(fa, x), fy = find(fa, y);
        if (fx == fy) continue;
        int time = fmax(times[fx], fmax(times[fy], logs[i][0]));
        if (fx < fy) {
            fa[fy] = fx;
            times[fx] = time;
        } else {
            fa[fx] = fy;
            times[fy] = time;
        }
    }
    int num = 0, id = -1;
    for (int i = 0; i < n; i++) {
        if (i == find(fa, i)) {
            num++;
            id = i;
            if (num > 1) return -1;
        }
    } 
    return times[id];
}