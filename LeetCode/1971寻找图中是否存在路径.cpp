int find(int *fa, int x) {
    if (fa[x] != x) {
        fa[x] = find(fa, fa[x]);
    }
    return fa[x];
}

bool merge(int *fa, int *size, int a, int b) {
    a = find(fa, a), b = find(fa, b);
    if (a == b) return true;
    if (size[a] > size[b]) fa[b] = a;
    else {
        if (size[a] == size[b]) size[b]++;
        fa[a] = b;
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    int fa[n + 5], size[n + 5];
    for (int i = 0; i < n + 5; i++) {
        fa[i] = i;
        size[i] = i;
    }
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0], y = edges[i][1];
        merge(fa, size, x, y);
    }
    return merge(fa, size, source, destination);
}