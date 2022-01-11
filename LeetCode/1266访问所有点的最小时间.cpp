int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int ans = 0, x0 = points[0][0], x1 = points[0][1];
    for (int i = 1; i < pointsSize; i++) {
        int y0 = points[i][0], y1 = points[i][1];
        ans += fmax(abs(x0 - y0), abs(x1 - y1));
        x0 = y0;
        x1 = y1;
    }
    return ans;
}