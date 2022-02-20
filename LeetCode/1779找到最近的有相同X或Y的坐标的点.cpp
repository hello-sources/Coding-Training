int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int min = INT_MAX, dis;
    int ind = -1;
    for (int i = 0; i < pointsSize; i++) {
        if (points[i][0] == x || points[i][1] == y) {
            dis = fabs(points[i][0] - x) + fabs(points[i][1] - y);
            if (dis < min) {
                min = dis;
                ind = i;
            }
        }
    }
    return ind;
}