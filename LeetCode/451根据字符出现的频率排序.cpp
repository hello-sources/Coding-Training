typedef struct {
    int cnt;
    char ch;
} Pair;

int cmp(const void *a, const void *b) {
    Pair pa = *(Pair *)a;
    Pair pb = *(Pair *)b;
    return pb.cnt - pa.cnt;
}

char * frequencySort(char * s){
    Pair *pair = (Pair *)malloc(sizeof(Pair) * 130);
    memset(pair, 0, sizeof(Pair) * 130);  
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len+ 5));
    for (int i = 0; i < len; i++) {
        int ind = s[i] - ' ';
        pair[ind].ch = s[i];
        pair[ind].cnt++;
    }
    qsort(pair, 130, sizeof(pair), cmp);
    int i, size = 0;
    for (i = 0; i < 130; i++) {
        if (pair[i].cnt != 0) {
            for (int j = 0; j < pair[i].cnt; j++) {
                res[size++] = pair[i].ch;
            }
        }
    }
    res[size] = '\0';
    return res;
}