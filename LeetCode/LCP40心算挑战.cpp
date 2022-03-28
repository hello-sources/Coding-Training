int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxmiumScore(int* cards, int cardsSize, int cnt){
    qsort(cards, cardsSize, sizeof(cards[0]), cmp);
    int ans = 0, flag = 0, sum = 0;
    for (int i = 0; i < cnt; i++) {
        sum += cards[i];
    }
    if (sum % 2 == 0) return sum;
    for (int i = cnt - 1; i >= 0; i--) {
        int tmp = sum;
        if (cards[i] % 2 == 0) {
            for (int j = cnt; j < cardsSize; j++) {
                if (cards[j] % 2 == 1) {
                    tmp -= cards[i];
                    tmp += cards[j];
                    ans = fmax(ans, tmp);
                    break;
                }
            }
        } else {
            for (int j = cnt; j < cardsSize; j++) {
                if (cards[j] % 2 == 0) {
                    tmp -= cards[i];
                    tmp += cards[j];
                    ans = fmax(ans, tmp);
                    break;
                }
            }
        }
    }
    return ans;
}