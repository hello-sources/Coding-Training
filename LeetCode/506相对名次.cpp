/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Data {
    int val;
    int ind;
} Data;

int cmp(const void *a, const void *b) {
    Data *A = (Data *)a;
    Data *B = (Data *)b;
    return A->val >= B->val ? -1 : 1;
}

char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){
    char *str[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    Data ret[scoreSize + 5];
    for (int i = 0; i < scoreSize; i++) {
        ret[i].val = score[i];
        ret[i].ind = i;
    }
    qsort(ret, scoreSize, sizeof(ret[0]), cmp);
    *returnSize = scoreSize;
    char **res = (char **)calloc(scoreSize, sizeof(char *));
    for (int i = 0; i < scoreSize; i++) {
        res[ret[i].ind] = (char *)calloc(15, sizeof(char));
        if (i < 3) {
            strcpy(res[ret[i].ind], str[i]);
        } else {
            sprintf(res[ret[i].ind], "%d", i + 1);
        }
    }
    return res;
}