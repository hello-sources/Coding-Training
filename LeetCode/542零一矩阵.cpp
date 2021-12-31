/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int m = matSize, n = matColSize[0];
    int queue[m * n][2], head = 0, tail = 0;
    bool visited[m][n];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) {
                visited[i][j] = true;
                queue[tail][0] = i;
                queue[tail++][1] = j;
            }
        }
    }
    int x, y, tx, ty;
    while (head != tail) {
        x = queue[head][0];
        y = queue[head++][1];
        for (int i = 0; i < 4; i++) {
            tx = x + a[i];
            ty = y + b[i];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && !visited[tx][ty]) {
                visited[tx][ty] = true;
                queue[tail][0] = tx;
                queue[tail++][1] = ty;
                mat[tx][ty] = mat[x][y] + 1;
            }
        }
    }
    *returnSize = matSize;
    (*returnColumnSizes) = (int*)malloc(matSize * sizeof(int));
    memcpy(*returnColumnSizes, matColSize, matrixSize * sizeof(int));
    return mat;
}