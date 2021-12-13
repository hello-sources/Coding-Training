/**
 * 扩展域的并查集算法
 * 此题将数组分成两个区域，分别是敌对域和友好域
 * 遵循“朋友的朋友就是敌人，需要加入敌对圈”原则
 */

#define MAX_N 5005
int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
    int fa[MAX_N];
    for (int i = 0; i < 2 * (n + 1) + 1; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < dislikesSize; i++) {
        int x = find(fa, dislikes[i][0]);
        int y = find(fa, dislikes[i][1]);
        int xx = find(fa, dislikes[i][0] + n + 1);
        int yy = find(fa, dislikes[i][1] + n + 1);
        if (x == y) return false;
        else {
            fa[xx] = y;
            fa[yy] = x;
        }
    }
    return true;
}