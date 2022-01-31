
typedef struct{
    char *key;
    int count;
    UT_hash_handle hh;
} CountMapEntry;

static int size = 100;

// 这里要传进来CountMapEntry ** 
static void countWord(CountMapEntry **map, char *sentence){
    char *p;
    CountMapEntry *entry;
    for(p=strtok(sentence, " "); p!=NULL; p=strtok(NULL, " ")){
        HASH_FIND_STR(*map, p, entry);
        if(entry==NULL){
            entry = (CountMapEntry *)malloc(sizeof(CountMapEntry));
            entry->key = p;
            entry->count = 1;
            HASH_ADD_STR(*map, key, entry);
        }else{
            entry->count++;
        }
    }
}

static void addWord(char **res, int cnt, char *word){
    if(cnt>=size){
        size *= 2;
        res = (char **)realloc(size, sizeof(char *));
    }
    res[cnt] = word;
}

static int findUncommon(CountMapEntry *countMap, char ** res){
    int cnt = 0;
    CountMapEntry *entry, *tmp;
    HASH_ITER(hh, countMap, entry, tmp) {
        if(entry->count==1){
            addWord(res, cnt++, entry->key);
        }
        HASH_DEL(countMap, entry);
        free(entry);
    }
    return cnt;
}

char ** uncommonFromSentences(char * A, char * B, int* returnSize){
    char **ret = (char **)calloc(size, sizeof(char *));
    CountMapEntry *countMap=NULL;
    countWord(&countMap, A);
    countWord(&countMap, B);
    *returnSize = findUncommon(countMap, ret);
    return ret;
}