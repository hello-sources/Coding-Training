/**
 * 先考虑grid2，判断它的连通性，找到对应的岛屿，然后观察每个岛屿是否包含在gird1中，其中对于水域
 * 父亲节点设置为-1，我们可以把每个连通分量最前面的父节点，记录下来
 * 与gird1进行比较，如果对应位置是水域，那么就可以把这个父节点剔除出去了，最后统计剩下的还有多少连通分量即可。
 * **/

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int *size, int *x, int *y) {
    int fx = find(fa, x), fy = find(fa, y);
    if (fx == fy) return ;
    if (size[fx] < size[fy]) swap(fx, fy);
    fa[fy] = fx;
    size[fx] += size[fy];
    return ;
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize){
    int m = grid2Size, n = grid2ColSize[0];
    int fa[m * n], size[m * n], temp[m * n], num[m * n];
    for (int i = 0; i < m * n; i++) {
        fa[i] = i;
        size[i] = 1;
        num[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                if (j + 1 < n && grid2[i][j + 1] == 1) {
                    merge(fa, size, i * n + j, i * n + j + 1);
                } 
                if (i + 1 < m && grid2[i + 1][j] == 1) {
                    merge(fa, size, i * n + j, (i + 1) * n + j);
                }
            } else {
                fa[i * n + j] = -1;
            }
        }
    }
    for (int i = 0; i < m * n; i++) {
        temp[i] = fa[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (fa[i * n + j] >= 0 && grid1[i][j] == 0) temp[find(fa, i * n + j)] = -1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < m * n; i++) {
        if (temp[i] >= 0 && temp[i] == i) num[i] = 1; 
    }
    for (int i = 0; i < m * n; i++) {
        if (num[i] == 1) cnt += 1;
    }
    return cnt;
}