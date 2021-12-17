/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/**
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 * 注意！带有*returnSize的需要使用malloc或者calloc进行开辟空间！
 */

#define swap(a, b) {\
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int *size, bool* isWater, int x, int y) {
    int fx = find(fa, x), fy = find(fa, y);
    if (fx == fy) return ;
    if (size[fx] < size[fy]) swap(fx, fy);
    isWater[fx] = true;
    isWater[fy] = true;
    fa[fy] = fx;
    size[fx] += size[fy];
    return ;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    int m = landSize, n = landColSize[0];
    *returnSize = 0;
    int fa[m * n], size[m * n];
    int *num = (int *)malloc(sizeof(int) * m * n);
    int cnt = 0;
    bool isWater[m * n];
    for (int i = 0; i < m * n; i++) {
        fa[i] = i;
        size[i] = 1;
        isWater[i] = false;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cur = i * n + j;
            if (land[i][j] == 0) {
                isWater[cur] = true;
                if (j > 0 && land[i][j - 1] == 0) merge(fa, size, isWater, cur, cur - 1);
                if (i > 0 && land[i - 1][j] == 0) merge(fa, size, isWater, cur, cur - n);
                if (i > 0 && j > 0 && land[i - 1][j - 1] == 0) merge(fa, size, isWater, cur, cur - n - 1);
                if (i > 0 && j < n - 1 && land[i - 1][j + 1] == 0) merge(fa, size, isWater, cur, cur - n + 1);
            }
        }
    }
    for (int i = 0; i < m * n; i++) {
        int temp = 0;
        if (find(fa, i) == i && isWater[i]) temp = size[i];
        else temp = -1;
        if (temp > 0) num[(*returnSize)++] = temp;
    }
    qsort(num, *returnSize, sizeof(int), cmp);
    return num;
}