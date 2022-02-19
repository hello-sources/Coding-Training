int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int halfQuestions(int* questions, int questionsSize){
    int cnt[1001] = {0}, ans = 0, sum = 0;
    for (int i = 0; i < questionsSize; i++) {
        cnt[questions[i]]++;
    }
    qsort(cnt, 1001, sizeof(int), cmp);
    for(int i = 0; i < 1001; i++) {
        sum += cnt[i];
        if (sum >= questionsSize / 2) return i + 1;
    }
    return 0;
}