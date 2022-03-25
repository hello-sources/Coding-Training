typedef struct {
    int cnt;
    char *str[30005];
} Trie;

Trie* trieCreate() {
    Trie *obj = (Trie *)malloc(sizeof(Trie));
    obj->cnt = 0;
    return obj;    
}

void trieInsert(Trie* obj, char * word) {
    obj->str[obj->cnt++] = word;
    return ;
}

bool trieSearch(Trie* obj, char * word) {
    for (int i = 0; i < obj->cnt; i++) {
        if (strcmp(obj->str[i], word) == 0) return true;
    }
    return false;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    for (int i = 0; i < obj->cnt; i++) {
        if (strncmp(prefix, obj->str[i], strlen(prefix)) == 0) return true;
    }
    return false;
}

void trieFree(Trie* obj) {
    free(obj);
    return ;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/