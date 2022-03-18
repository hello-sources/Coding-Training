typedef struct trie{
    bool isend;
    struct trie *children[26];
}Trie;
Trie *creat(){
    Trie *root = malloc(sizeof(Trie));
    memset(root,0,sizeof(Trie));
    root -> isend = false;
    return root;
}
void insert(Trie *root, char *word){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        int ch = word[i] - 'a';
        if(root -> children[ch] == NULL){
            root -> children[ch] = creat(); 
        }
        root = root -> children[ch];
    }
    root -> isend = true;
}
bool search(Trie *root, char *word){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        int ch = word[i] - 'a';  // 这一步很关键，如果判定这个支付串不是由前一个组成的直接返回false
        if(root -> children[ch] == NULL || root -> children[ch] -> isend == false){
            return false;
        }
        root = root -> children[ch];
    }
    return root -> isend;
}
int cmp(char **a, char **b){  // 先按长度排序，长度相同按照字典序排序
    return strlen(*b) != strlen(*a) ? strlen(*b) - strlen(*a) : strcmp(*a,*b);
}
char * longestWord(char ** words, int wordsSize){
    if(wordsSize == 0){
        return "";
    }
    Trie *root = creat();
    for(int i = 0; i < wordsSize; i++){
        insert(root,words[i]);
    }
    qsort(words,wordsSize,sizeof(char*),cmp);
    for(int i = 0; i < wordsSize; i++){
        if(search(root,words[i])){
            return words[i];
        }
    }
    return "";
}