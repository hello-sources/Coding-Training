/*******************超时做法*************************/
#define swap(a, b) {\
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}
typedef struct Data {
    int first, second;
};

int cmp(const void *a, const void *b) {
    const struct Data *pa = a;
    const struct Data *pb = b;
    if (pa->first == pb->first) {
        return pa->second - pb->second;
    } else return pa->first - pb->first;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int cnt = 0;
    struct Data *data = (struct Data *)malloc(sizeof(struct Data) * dominoesSize);
    for (int i = 0; i < dominoesSize; i++) {
        if (dominoes[i][0] > dominoes[i][1]) swap(dominoes[i][0], dominoes[i][1]);
    }
    for (int i = 0; i < dominoesSize; i++) {
        data[i].first = dominoes[i][0];
        data[i].second = dominoes[i][1];
    } 
    qsort(data, dominoesSize, sizeof(struct Data), cmp);
    for (int i = 0; i < dominoesSize; i++) {
        for (int j = i + 1; j < dominoesSize; j++) {
            if (dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) cnt++;
        }
    }
    return cnt;
}

/***************参考题解************************/
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int num[100] = {0};
    int cnt = 0;
    for (int i = 0; i < dominoesSize; i++) {
        int val = dominoes[i][0] > dominoes[i][1] ? dominoes[i][1] * 10 + dominoes[i][0] : dominoes[i][0] * 10 + dominoes[i][1];
        cnt += num[val];
        num[val]++;
    }
    return cnt;
}