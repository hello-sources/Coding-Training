/*********************按照逆向顺序进行模拟******************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void imitate(int *res, int ind) {
    if (ind == 0) return ;
    int temp = res[ind - 1];
    for (int i = ind - 1; i > 0; i--) {
        res[i] = res[i - 1];
    }
    res[0] = temp;
    return ;
}

void imitate_set(int *res, int ind, int target) {
    for (int i = ind - 1; i > 0; i--) {
        res[i] = res[i - 1];
    }
    res[0] = target;
    return ;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
    qsort(deck, deckSize, sizeof(int), cmp);
    int *res = (int *)malloc(sizeof(int) * deckSize);
    *returnSize = deckSize;
    memset(res, 0, sizeof(int) * deckSize);
    int ind = 0;
    for (int i = deckSize - 1; i >= 0; i--) {
        imitate(res, ind);
        ind++;
        imitate_set(res, ind, deck[i]);
    }
    return res;
}

/******************大佬的差位填空*******************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
    qsort(deck, deckSize, sizeof(int), cmp);
    int *res = (int *)malloc(sizeof(int) * deckSize);
    *returnSize = deckSize;
    memset(res, 0, sizeof(int) * deckSize);
    int ind = 0;
    res[0] = deck[0];
    for (int i = 1; i < deckSize; i++) {
        while (res[ind] != 0) {
            ind = (ind + 1) % deckSize;
        }
        ind = (ind + 1) % deckSize;
        while (res[ind] != 0) {
            ind = (ind + 1) % deckSize;
        }
        res[ind] = deck[i];
    }
    return res;
}