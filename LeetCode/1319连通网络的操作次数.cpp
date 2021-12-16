#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

int merge(int *fa, int *size, int a, int b) {
    int A = find(fa, a), B = find(fa, b);
    if (A == B) return 0;
    if (size[A] < size[B]) swap(A, B);
    fa[B] = A;
    size[A] += size[B];
    return 1; 
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    int cnt = n, temp = 0;
    int fa[n], size[n];
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < connectionsSize; i++) {
        if (merge(fa, size, connections[i][0], connections[i][1])) cnt--;
        else temp++;
    }
    if (temp < cnt - 1) return -1;
    return cnt - 1;
}