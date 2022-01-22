/****************跳跃游戏****************/
typedef struct IdxHashEntry {
    int key;               
    struct ListNode * head;
    UT_hash_handle hh;         
}IdxHashEntry;

typedef struct SetHashEntry {
    int key; 
    UT_hash_handle hh;         
}SetHashEntry;

typedef struct Pair {
    int idx;
    int step;
}Pair;

void hashAddIdxItem(struct IdxHashEntry **obj, int key, int val) {
    struct IdxHashEntry *pEntry = NULL;
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    HASH_FIND(hh, *obj, &key, sizeof(key), pEntry);
    if (NULL == pEntry) {
        pEntry = (struct IdxHashEntry *)malloc(sizeof(struct IdxHashEntry));
        pEntry->key = key;
        pEntry->head = node;
        HASH_ADD(hh, *obj, key, sizeof(int), pEntry);
    } else {
        node->next = pEntry->head;
        pEntry->head = node;
    }
} 

struct IdxHashEntry *hashFindIdxItem(struct IdxHashEntry **obj, int key)
{
    struct IdxHashEntry *pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(int), pEntry);
    return pEntry;
}

void hashFreeIdxAll(struct IdxHashEntry **obj)
{
    struct IdxHashEntry *curr = NULL, *next = NULL;
    HASH_ITER(hh, *obj, curr, next)
    {
        HASH_DEL(*obj, curr);  
        free(curr);      
    }
}

void hashAddSetItem(struct SetHashEntry **obj, int key) {
    struct SetHashEntry *pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(key), pEntry);
    if (pEntry == NULL) {
        pEntry = malloc(sizeof(struct SetHashEntry));
        pEntry->key = key;
        HASH_ADD(hh, *obj, key, sizeof(int), pEntry);
    }
} 

struct SetHashEntry *hashFindSetItem(struct SetHashEntry **obj, int key)
{
    struct SetHashEntry *pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(int), pEntry);
    return pEntry;
}

void hashFreeSetAll(struct SetHashEntry **obj)
{
    struct SetHashEntry *curr = NULL, *next = NULL;
    HASH_ITER(hh, *obj, curr, next)
    {
        HASH_DEL(*obj, curr);  
        free(curr);      
    }
}

int minJumps(int* arr, int arrSize){
    struct IdxHashEntry * idxSameValue = NULL;
    for (int i = 0; i < arrSize; i++) {
        hashAddIdxItem(&idxSameValue, arr[i], i);
    }
    
    struct SetHashEntry * visitedIndex = NULL;
    struct Pair * queue = (struct Pair *)malloc(sizeof(struct Pair) * arrSize * 2);
    int head = 0;
    int tail = 0;
    queue[tail].idx = 0;
    queue[tail].step = 0;
    tail++;
    hashAddSetItem(&visitedIndex, 0);
    while (head != tail) {
        int idx = queue[head].idx;
        int step = queue[head].step;
        head++;
        if (idx + 1 == arrSize) {
            hashFreeIdxAll(&idxSameValue);
            hashFreeSetAll(&visitedIndex);
            free(queue);
            return step;
        }
        int v = arr[idx];
        step++;
        struct IdxHashEntry * pEntry = hashFindIdxItem(&idxSameValue, v);
        if (NULL != pEntry) {
            for (struct ListNode * node = pEntry->head; node; node = node->next) {
                if (NULL == hashFindSetItem(&visitedIndex, node->val)) {
                    hashAddSetItem(&visitedIndex, node->val);
                    queue[tail].idx = node->val;
                    queue[tail].step = step;
                    tail++;
                }
            }
            HASH_DEL(idxSameValue, pEntry);
        }
        if (idx + 1 < arrSize && NULL == hashFindSetItem(&visitedIndex, idx + 1)) {
            hashAddSetItem(&visitedIndex, idx + 1);
            queue[tail].idx = idx + 1;
            queue[tail].step = step;
            tail++;
        }
        if (idx - 1 >= 0 && NULL == hashFindSetItem(&visitedIndex, idx - 1)) {
            hashAddSetItem(&visitedIndex, idx - 1);
            queue[tail].idx = idx - 1;
            queue[tail].step = step;
            tail++;
        }
    }
    hashFreeIdxAll(&idxSameValue);
    hashFreeSetAll(&visitedIndex);
    free(queue);
    return -1;
}