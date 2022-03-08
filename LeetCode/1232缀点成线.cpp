bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
    for (int i = 0; i < coordinatesSize; ++i) {
        coordinates[i][0] -= deltaX;
        coordinates[i][1] -= deltaY;
    }
    int A = coordinates[1][1], B = -coordinates[1][0];
    for (int i = 2; i < coordinatesSize; ++i) {
        int x = coordinates[i][0], y = coordinates[i][1];
        if (A * x + B * y != 0) {
            return false;
        }
    }
    return true;
}