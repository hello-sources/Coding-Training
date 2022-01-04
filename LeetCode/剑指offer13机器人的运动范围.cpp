bool calc(int x, int y, int num) {
    int ans = 0;
    while (x || y) {
        ans += (x % 10 + y % 10);
        x /= 10;
        y /= 10;
    }
    return ans <= num ? true : false;
}

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

typedef struct Pair {
    int x, y;
} Pair;

int movingCount(int m, int n, int k){
    if (!k) return 1;
    Pair p[10001];
    int visited[101][101];
    int tail = 0, head = 0;
    memset(p, 0, sizeof(p));
    memset(visited, 0, sizeof(visited));
    p[tail].x = 0;
    p[tail++].y = 0;
    visited[0][0] = 1;
    while (head < tail) {
        for (int i = 0; i < 4; i++) {
            int tx = p[head].x + dir_x[i];
            int ty = p[head].y + dir_y[i];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
            if (calc(tx, ty, k) && !visited[tx][ty]) {
                p[tail].x = tx;
                p[tail++].y = ty;
                visited[tx][ty] = 1;
            }
        }
        head++;
    }
    return head ? head : 0;
}