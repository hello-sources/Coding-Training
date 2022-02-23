/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int **image, int imageSize, int imageColSize, int sr, int sc, int newColor, int oldColor) {
    if (sr < 0 || sc < 0 || sr >= imageSize || sc >= imageColSize) return ;
    int color = image[sr][sc];
    if (color == oldColor && color != newColor) {
        image[sr][sc] = newColor;
        dfs(image, imageSize, imageColSize, sr - 1, sc, newColor, oldColor);
        dfs(image, imageSize, imageColSize, sr, sc - 1, newColor, oldColor);
        dfs(image, imageSize, imageColSize, sr + 1, sc, newColor, oldColor);
        dfs(image, imageSize, imageColSize, sr, sc + 1, newColor, oldColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    dfs(image, imageSize, imageColSize[0], sr, sc, newColor, image[sr][sc]);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}