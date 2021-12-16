/***********并查集做法************/
#define MAX_N 90000
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int fa[MAX_N], size[MAX_N];

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

int countServers(int** grid, int gridSize, int* gridColSize){
    for (int i = 0; i < MAX_N; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < gridSize; k++) {
                    if (k != i && grid[k][j] == 1) {
                        merge(fa, i * gridColSize[0] + j, k * gridColSize[0] + j);
                        break;
                    }
                }
                for (int k = 0; k < gridColSize[0]; k++) {
                    if (k != j && grid[i][k] == 1) {
                        merge(fa, i * gridColSize[0] + j, i * gridColSize[0] + k);
                        break;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (fa[i] == i && size[i] > 1) {
            ans += size[i];
        }
    }
    return ans;
}


/*********************每行每列分别计数*********************/
#define MAX_N 255
int countServers(int** grid, int gridSize, int* gridColSize){
    int cnt_m[MAX_N], cnt_n[MAX_N];
    memset(cnt_m, 0, sizeof(cnt_m));
    memset(cnt_n, 0, sizeof(cnt_n));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                cnt_m[i]++;
                cnt_n[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1 && (cnt_m[i] > 1 || cnt_n[j] > 1)) ans++;
        }
    }
    return ans;
}