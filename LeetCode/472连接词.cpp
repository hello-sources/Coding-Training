/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct Trie {
     struct Trie* child[26];
     bool end;
 } Trie;

int cmp(const void *a, const void *b){
    int la = strlen(*(char **)a);
    int lb = strlen(*(char **)b);
    return la - lb;
}

void init_Trie(Trie *node) {
    for (int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }
    node->end = false;
}

void free_trie(struct Trie *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        if (node->child[i] != NULL) free(node->child[i]);
    }
    free(node);
    return ;
}

bool dfs(Trie *trie, char *word, int wordsSize, int start) {
    if (wordsSize == start) return true;
    Trie *node = trie;
    for (int i = start; i < wordsSize; i++) {
        char ch = word[i];
        int index = ch - 'a';
        node = node->child[index];
        if (node == NULL) return false;
        if (node->end) {
            if (dfs(trie, word, wordsSize, i + 1)) return true;
        }
    }
    return false;
}

void insert(Trie *trie, char *word, int wordsSize) {
    Trie *node = trie;
    for (int i = 0; i < wordsSize; i++) {
        char ch = word[i];
        int index = ch - 'a';
        if (node->child[index] == NULL) {
            node->child[index] = (Trie *)malloc(sizeof(Trie));
            init_Trie(node->child[index]);
        } 
        node = node->child[index];
    }
    node->end = true;
    return ;
}

char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
    int pos = 0;
    char **ans = (char **)malloc(sizeof(char *) * wordsSize);
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    init_Trie(trie);
    qsort(words, wordsSize, sizeof(char *), cmp);
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        if (len == 0) continue;
        if (dfs(trie, words[i], len, 0)) {
            ans[pos] = (char *)malloc(sizeof(char) * (len + 1));
            strncpy(ans[pos], words[i], len);
            ans[pos][len] = '\0';
            pos++;
        } else {
            insert(trie, words[i], len);
        }
    }
    free_trie(trie);
    *returnSize = pos;
    return ans;
}