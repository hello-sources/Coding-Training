typedef struct {
    int cnt;
    char *str[30005];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *obj = (Trie *)malloc(sizeof(Trie));
    obj->cnt = 0;
    memset(obj->str, 0, sizeof(obj->str));
    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    obj->str[obj->cnt++] = word;
    return ;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    for (int i = 0; i < obj->cnt; i++) {
        if (strcmp(obj->str[i], word) == 0) return true;
    }
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
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