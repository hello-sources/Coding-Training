#define MAX_N 3000
#define swap(a, b) {\
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int size[MAX_N];
int fa[MAX_N];

void init(int x) {
    for (int i = 0; i < x; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    return ;
}

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return ;
    if (size[a] > size[b]) swap(a, b);
    fa[a] = b;
    size[b] += size[a];
    return ;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0, flag = 0;
    init(gridSize * gridColSize[0]);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            int ind = i * gridColSize[0] + j;
            if (grid[i][j] == 1) {
                flag = 1;
                if (i + 1 < gridSize && grid[i + 1][j] == 1) merge(ind, ind + gridColSize[0]);
                if (j + 1 < gridColSize[0] && grid[i][j + 1] == 1) merge(ind, ind + 1);
            }
        }
    }
    if (!flag) return 0;
    for (int i = 0; i < gridSize * gridColSize[0]; i++) {
        max = fmax(max, size[i]);
    }
    return max;
}