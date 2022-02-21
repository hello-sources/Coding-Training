/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(res, 0, sizeof(int) * 2);
    int min = INT_MAX, l = area;
    for (int i = area; i >= 1; i--) {
        if (area % i != 0) continue;
        else {
            if (min > fabs(i - area / i)) {
                l = i;
                min = fabs(i - area / i);
            }
        }
    }
    res[0] = l;
    res[1] = area / l;
    return res;
}