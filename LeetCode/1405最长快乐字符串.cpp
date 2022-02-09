typedef struct {
    int fre;
    char ch;
} Pair; 

int cmp(const void *a, const void *b) {
    return ((Pair *)b)->fre - ((Pair *)a)->fre;
}

char * longestDiverseString(int a, int b, int c){
    char *res = (char *)malloc(sizeof(char) * (a + b + c + 1));
    Pair arr[3] = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    int pos = 0;
    while (true) {
        qsort(arr, 3, sizeof(Pair), cmp);
        bool hasNext = false;AC
        for (int i = 0; i < 3; i++) {
            int fre = arr[i].fre;
            int ch = arr[i].ch;
            if (fre <= 0) break;
            if (pos >= 2 && res[pos - 2] == ch && res[pos - 1] == ch) continue;
            hasNext = true;
            res[pos++] = ch;
            arr[i].fre--;
            break;
        }
        if (!hasNext) break;
    }
    res[pos] = '\0';
    return res;
}