/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_N 1005
int cmp(const void *a, const void *b) {
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    if (pa[0] == pb[0]) return pb[1] - pa[1];
    return pa[0] - pb[0];
}

int** highFive(int** items, int itemsSize, int* itemsColSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * (itemsSize / 5));
    int cnt = 0, id = 0, sum = 0, sub = 0;
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (itemsSize / 5));
    for (int i = 0; i < itemsSize / 5; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    qsort(items, itemsSize, sizeof(int *), cmp);
    for (int i = 0; i < itemsSize; i++) {
        if (items[i][0] != id) {
            id = items[i][0];
            res[cnt++][0] = id;
            sum += items[i][1];
            sub = 1;
        } else if (sub < 5) {
            sub++;
            sum += items[i][1];
            if (sub == 5) {
                res[cnt - 1][1] = sum / 5;
                sum = 0;
            }
        }
    }
    *returnSize = cnt;
    return res;
}