/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes){
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageColSize[0] / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][imageColSize[0] - j - 1];
            image[i][imageColSize[0] - j - 1] = temp;
        }
    }
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageColSize[0]; j++) {
            if (image[i][j]) image[i][j] = 0;
            else image[i][j] = 1;
        }
    }
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}