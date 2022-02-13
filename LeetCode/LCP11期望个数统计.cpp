int expectNumber(int* scores, int scoresSize){
    int num[1000005] = {0}, cnt = 0;
    for (int i = 0; i < scoresSize; i++) {
        if (num[scores[i]] == 0) {
            cnt++;
            num[scores[i]]++;
        }
    }
    return cnt;
}