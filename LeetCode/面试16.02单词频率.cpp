typedef struct {
    int cnt;
    char str[15];
    UT_hash_handle hh;
} WordsFrequency;

WordsFrequency *g_test = NULL;

void addStr(char *str) {
    WordsFrequency *s = NULL;
    HASH_FIND_STR(g_test, str, s);
    if (s == NULL) {
        s = (WordsFrequency *)malloc(sizeof(WordsFrequency));
        strcpy(s->str, str);
        s->cnt = 1;
        HASH_ADD_STR(g_test, str, s);
    } else {
        s->cnt++;
    }
    return ;
}

WordsFrequency* wordsFrequencyCreate(char** book, int bookSize) {
    for (int i = 0; i < bookSize; i++) {
        addStr(book[i]);
    }
    return g_test;
}

int wordsFrequencyGet(WordsFrequency* obj, char* word) {
    WordsFrequency *s = NULL;
    HASH_FIND_STR(g_test, word, s);
    if (s == NULL) return 0;
    return s->cnt;
}

void wordsFrequencyFree(WordsFrequency* obj) {
    WordsFrequency *iter, *temp;
    HASH_ITER(hh, g_test, iter, temp) {
        HASH_DEL(g_test, iter);
        free(iter);
    }
    return ;
}

/**
 * Your WordsFrequency struct will be instantiated and called as such:
 * WordsFrequency* obj = wordsFrequencyCreate(book, bookSize);
 * int param_1 = wordsFrequencyGet(obj, word);
 
 * wordsFrequencyFree(obj);
*/