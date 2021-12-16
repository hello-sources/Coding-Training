/**
 * 并查集模板题
 * 值得注意的是对于边界条件的判断，设置一个边界点，如果连通分量有的点在边界上
 * 直接把对应的节点的父节点更新为设定的边界点，最后经历两层遍历判断对应点值为1
 * 且不等于设置的那个特殊的点的连通分量都是飞地。
*/

#define MAX_N 250005
int fa[MAX_N], size[MAX_N];

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int a, int b) {
    int A = find(fa, a), B = find(fa, b);
    if (A == B) return ;
    if (size[A] > size[B]) {
        fa[B] = A;
        size[A] += size[B];
    } else {
        fa[A] = B;
        size[B] += size[A];
    }
    return ;
}

int numEnclaves(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    for (int i = 0; i < MAX_N; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                if (i == 0 || j == 0 || i == (m - 1) || j == (n - 1)) {
                    merge(fa, m * n, i * n + j);
                } else {
                    if (grid[i][j - 1] == 1) merge(fa, i * n + j, i * n + j - 1);
                    if (grid[i][j + 1] == 1) merge(fa, i * n + j, i * n + j + 1);
                    if (grid[i - 1][j] == 1) merge(fa, i * n + j, (i - 1) * n + j);
                    if (grid[i + 1][j] == 1) merge(fa, i * n + j, (i + 1) * n + j);
                }
            }    
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && (find(fa, i * n + j) != find(fa, m * n))) ans++;
        }
    }
    return ans;
}