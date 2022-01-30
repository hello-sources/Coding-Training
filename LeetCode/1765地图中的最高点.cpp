/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct Pair {
    int x, y;
} Pair;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes){
    int m = isWaterSize, n = isWaterColSize[0];
    int **ans = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        ans[i] = (int *)malloc(sizeof(int) * n);
        memset(ans[i], -1, sizeof(int) * n);
    }
    Pair *queue = (Pair *)malloc(sizeof(Pair) * m * n);
    int head = 0, tail = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j]) {
                ans[i][j] = 0;
                queue[tail].x = i;
                queue[tail++].y = j;
            }
        }
    }
    while (head != tail) {
        int px = queue[head].x, py = queue[head].y;
        for (int i = 0; i < 4; i++) {
            int x = px + dir[i][0], y = py + dir[i][1];
            if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                ans[x][y] = ans[px][py] + 1;
                queue[tail].x = x;
                queue[tail++].y = y;
            }
        }
        head++;
    }
    free(queue);
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    memcpy(*returnColumnSizes, isWaterColSize, sizeof(int) * m);
    return ans;
}