double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    double ans = 0, temp;
    for (int i = 0; i < pointsSize - 2; i++) {
        for (int j = i + 1; j < pointsSize - 1; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                if((points[i][0] - points[j][0]) * (points[j][1] - points[k][1]) != (points[i][1] - points[j][1]) * (points[j][0] - points[k][0])){
                   temp = abs(points[i][0] * points[j][1] + points[i][1] * points[k][0] + points[j][0] * points[k][1] - points[i][0] * points[k][1] - points[i][1] * points[j][0] - points[j][1] * points[k][0])/2.0;
                   ans = fmax(ans, temp);
                }
            }
        }
    }
    return ans;
}