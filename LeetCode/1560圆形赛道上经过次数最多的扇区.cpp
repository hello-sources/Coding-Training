/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * n);
    int i = 1, j = 0;
    while (i <= n) {
        if (rounds[0] <= rounds[roundsSize - 1] && rounds[0] <= i && i <= rounds[roundsSize - 1]) res[j++] = i;
        if (rounds[0] > rounds[roundsSize - 1] && (rounds[0] <= i || i <= rounds[roundsSize - 1])) res[j++] = i;
        i++;
    }
    *returnSize = j;
    return res;
}

/**************qsort做法**************/
#define MAX_N 101
typedef struct Cnt {
    int fre, num;
};

int cmp(const void *a, const void *b) {
    const struct Cnt *pa = a;
    const struct Cnt *pb = b;
    if (pa->fre != pb->fre) {
        return pb->fre - pa->fre;
    } else {
        return pa->num - pb->num;
    }
}

int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize){
    struct Cnt *cnt_num = (struct Cnt *)malloc(sizeof(struct Cnt) * MAX_N);
    memset(cnt_num, 0, sizeof(struct Cnt) * MAX_N);
    int i = rounds[0], j = 1;
    cnt_num[i].num = i;
    cnt_num[i].fre++;
    while (true) {
        i++;
        if (i > n) i = 1;
        cnt_num[i].num = i;
        cnt_num[i].fre++;
        if (i == rounds[j]) {
            j++;
            if (j >= roundsSize) break;
        }
    }
    qsort(cnt_num, n + 1, sizeof(struct Cnt), cmp);
    *returnSize = 1;
    for (int i = 1; i < n; i++) {
        if (cnt_num[i].fre == cnt_num[0].fre) (*returnSize)++;
        else break;
    }
    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    memset(res, 0, sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        res[i] = cnt_num[i].num;
    }
    return res;
}