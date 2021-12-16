#define MAX_N 10005
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}
int fa[MAX_N], size[MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    return ;
}

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int a, int b) {
    int A = find(fa, a), B = find(fa, b);
    if (A == B) return ;
    if (size[A] < size[B]) swap(A, B);
    fa[B] = A;
    size[A] += size[B];
    return ;
}

int closedIsland(int** grid, int gridSize, int* gridColSize){
    init();
    int m = gridSize, n = gridColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    merge(fa, m * n, i * n + j);
                } else {
                    if (grid[i][j - 1] == 0) merge(fa, i * n + j, i * n + j - 1);
                    if (grid[i][j + 1] == 0) merge(fa, i * n + j, i * n + j + 1);
                    if (grid[i - 1][j] == 0) merge(fa, i * n + j, (i - 1) * n + j);
                    if (grid[i + 1][j] == 0) merge(fa, i * n + j, (i + 1) * n + j);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && (find(fa, i * n + j) != find(fa, m * n) && find(fa, i * n + j) == i * n + j)) ans++;
        }
    }
    return ans;
}