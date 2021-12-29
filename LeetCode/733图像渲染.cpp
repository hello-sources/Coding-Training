/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void DFS(int** image, int sr, int sc, int newColor,int old, int imageSize, int* imageColSize){
    if(sr<0||sr>=imageSize||sc<0||sc>=imageColSize[0]||image[sr][sc]!=old||image[sr][sc]==newColor){
        return;
    }
    image[sr][sc]=newColor;
    DFS(image,sr+1,sc,newColor,old,imageSize,imageColSize);
    DFS(image,sr-1,sc,newColor,old,imageSize,imageColSize);
    DFS(image,sr,sc+1,newColor,old,imageSize,imageColSize);
    DFS(image,sr,sc-1,newColor,old,imageSize,imageColSize);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    DFS(image,sr,sc,newColor,image[sr][sc],imageSize,imageColSize);
    *returnSize = imageSize;
	*returnColumnSizes = imageColSize;
    return image;
}