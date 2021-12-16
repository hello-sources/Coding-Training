/**
 * 这道题主要难点在于如何抽象出来连通性问题，根据官方题解，是把每个方格按照对角线
 * 划分成四个区域0， 1， 2， 3，当对应输入的是空格时，则表示四个区域都连通了
 * 如果是斜杠/，则表示0，3区域连通了，2，1区域连通了
 * 问题又来了，如何处理方格与方格之间的连通，
 * 其实无非就是向右连接，或者向下连接
 * **/


int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int a, int b) {
    int aa = find(fa, a), bb = find(fa, b);
    if (aa == bb) return ;
    fa[aa] = bb;
    return ;
}

int regionsBySlashes(char ** grid, int gridSize){
    int fa[gridSize * gridSize * 4];
    int len = gridSize * 4, cur;
    for (int i = 0; i < gridSize * gridSize * 4; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cur = i * len + j * 4;
            if (grid[i][j] == ' ') fa[cur] = fa[cur + 1] = fa[cur + 2] = fa[cur + 3];
            else if (grid[i][j] == '/') {
                fa[cur] = fa[cur + 1];
                fa[cur + 2] = fa[cur + 3];
            } else {
                fa[cur] = fa[cur + 3];
                fa[cur + 2] = fa[cur + 1];
            }
            if (i) {
                merge(fa, cur - len + 2, cur);
            }
            if (j) {
                merge(fa, cur - 1, cur + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < gridSize * len; i++) {
        if (find(fa, i) == i) ans++;
    }
    return ans;
}