int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int cnt = 0, i = 0, j = 0;
    for (; i < gSize; i++) {
        for (; j < sSize; j++) {
            if (s[j] < g[i]) continue;
            s[j] = 0;
            cnt++;
            break;
        }
    }
    return cnt;
}