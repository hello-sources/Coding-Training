typedef struct {
    int cnt[1001][1001];
} DetectSquares;

DetectSquares* detectSquaresCreate() {
    DetectSquares *obj = (DetectSquares *)malloc(sizeof(DetectSquares));
    memset(obj->cnt, 0, sizeof(int) * 1001 * 1001);
    return obj;
}

void detectSquaresAdd(DetectSquares* obj, int* point, int pointSize) {
    obj->cnt[point[0]][point[1]]++;
}

int detectSquaresCount(DetectSquares* obj, int* point, int pointSize) {
    int ans = 0, x, y;
    x = point[0] - 1, y = point[1] - 1;
    while (x >= 0 && y >= 0) {
        ans += obj->cnt[x][y] * obj->cnt[point[0]][y] * obj->cnt[x][point[1]];
        x--;
        y--;
    }
    x = point[0] - 1, y = point[1] + 1;
    while (x >= 0 && y < 1001) {
        ans += obj->cnt[x][y] * obj->cnt[point[0]][y] * obj->cnt[x][point[1]];
        x--;
        y++;
    }
    x = point[0] + 1, y = point[1] + 1;
    while (x < 1001 && y < 1001) {
        ans += obj->cnt[x][y] * obj->cnt[point[0]][y] * obj->cnt[x][point[1]];
        x++;
        y++;
    }
    x = point[0] + 1, y = point[1] - 1;
    while (x < 1001 && y >= 0) {
        ans += obj->cnt[x][y] * obj->cnt[point[0]][y] * obj->cnt[x][point[1]];
        x++;
        y--;
    }
    return ans;
}

void detectSquaresFree(DetectSquares* obj) {
    free(obj);
    return ;
}

/**
 * Your DetectSquares struct will be instantiated and called as such:
 * DetectSquares* obj = detectSquaresCreate();
 * detectSquaresAdd(obj, point, pointSize);
 
 * int param_2 = detectSquaresCount(obj, point, pointSize);
 
 * detectSquaresFree(obj);
*/