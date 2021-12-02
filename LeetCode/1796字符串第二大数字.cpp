int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int secondHighest(char * s){
    int len = strlen(s);
    int *ret = (int *)malloc(sizeof(int) * (len + 5));
    int cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] <= '9' && s[i] >= '0') {
            ret[cnt++] = s[i] - '0';
        }
    }
    if (cnt == 0) return -1;
    qsort(ret, cnt, sizeof(int), cmp);
    if (ret[0] == ret[cnt - 1]) return -1;
    int target = 0;
    for (int i = cnt - 1; i >= 1; i--) {
        if (ret[i] != ret[i - 1]) {
            target = ret[i - 1]; 
            break;
        }
    }
    return target;
}