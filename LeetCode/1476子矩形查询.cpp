#define MAX_N 105
typedef struct {
    int num[MAX_N][MAX_N];
} SubrectangleQueries;


SubrectangleQueries* subrectangleQueriesCreate(int** rectangle, int rectangleSize, int* rectangleColSize) {
    SubrectangleQueries *obj = (SubrectangleQueries *)malloc(sizeof(SubrectangleQueries));
    for (int i = 0; i < rectangleSize; i++) {
        for (int j = 0; j < rectangleColSize[0]; j++) {
            obj->num[i][j] = rectangle[i][j];
        }
    }
    return obj;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries* obj, int row1, int col1, int row2, int col2, int newValue) {
    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            obj->num[i][j] = newValue;
        }
    }
    return ;
}

int subrectangleQueriesGetValue(SubrectangleQueries* obj, int row, int col) {
    return obj->num[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries* obj) {
    free(obj);
    return ;
}

/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
 
 * int param_2 = subrectangleQueriesGetValue(obj, row, col);
 
 * subrectangleQueriesFree(obj);
*/