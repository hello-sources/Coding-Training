typedef struct {
    int cnt;
    char *word;
} Pair;

Pair *pair;

void process(char *paragraph) {
    char *tp = paragraph;
    while (*tp) {
        if (*tp == '!' || *tp == '?' || *tp == ',' || *tp == ';' || *tp == '.' || *tp == '\'') {
            *tp = ' ';
        } else if (*tp <= 'Z' && *tp >= 'A') {
            *tp += 32;
        }
        *tp++;
    }
    return ;
}

void save(char *str, int *size) {
    for (int i= 0; i < *size; i++) {
        if (strcmp(pair[i].word, str) == 0) {
            pair[i].cnt++;
            return ;
        }
    }
    pair[*size].word = str;
    pair[(*size)++].cnt = 1;
    return ;
}

int cmp(const void *a, const void *b) {
    Pair pa = *(Pair *)a;
    Pair pb = *(Pair *)b;
    return pb.cnt - pa.cnt;
}

bool judge(char *t, char **p, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(t, p[i]) == 0) return true;
    }
    return false;
}

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    process(paragraph);
    pair = (Pair *)malloc(sizeof(Pair) * 1000);
    memset(pair, 0, sizeof(Pair) * 1000);
    int word_cnt = 0;
    char *p = strtok(paragraph, " ");
    while (p) {
        save(p, &word_cnt);
        p = strtok(NULL, " ");
    }
    qsort(pair, word_cnt, sizeof(Pair), cmp);
    for (int i = 0; i < word_cnt; i++) {
        if (judge(pair[i].word,  banned, bannedSize) == false) return pair[i].word;
    }
    return NULL;
}