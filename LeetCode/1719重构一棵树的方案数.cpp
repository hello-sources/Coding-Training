typedef struct {
    int key;
    UT_hash_handle hh;
} HashEntry;

void hashInsert(HashEntry ** obj, int key) {
    HashEntry * pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(int), pEntry);
    if (NULL == pEntry) {
        pEntry = (HashEntry *)malloc(sizeof(HashEntry));
        pEntry->key = key;
        HASH_ADD(hh, *obj, key, sizeof(int), pEntry);
    }
}

bool hashFind(HashEntry ** obj, int key) {
    HashEntry * pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(int), pEntry);
    if (NULL == pEntry) {
        return false;
    } else {
        return true;
    }
}

void hashFreeAll(HashEntry ** obj) {
    HashEntry *curr, *next;
    HASH_ITER(hh, *obj, curr, next) {
        HASH_DEL(*obj, curr);  
        free(curr);
    }
}

#define MAX_NODE_SIZE 501

int checkWays(int** pairs, int pairsSize, int* pairsColSize) {
    HashEntry * adj[MAX_NODE_SIZE];
    memset(adj, 0, sizeof(HashEntry *) * MAX_NODE_SIZE);
    for (int i = 0; i < pairsSize; i++) {
        hashInsert(&adj[pairs[i][0]], pairs[i][1]);
        hashInsert(&adj[pairs[i][1]], pairs[i][0]);
    }
    int nodeSize = 0;
    for (int i = 0; i < MAX_NODE_SIZE; i++) {
        if (NULL != adj[i]) {
            nodeSize++;
        }
    }
    /* 检测是否存在根节点*/
    int root = -1;
    for (int i = 0; i < MAX_NODE_SIZE; i++) {
        unsigned int degree = HASH_COUNT(adj[i]);
        if (degree == nodeSize - 1) {
            root = i;
            break;
        }
    }
    if (root == -1) {
        return 0;
    }

    int res = 1;
    for (int i = 0; i < MAX_NODE_SIZE; i++) {
        if (root == i || NULL == adj[i]) {
            continue;
        }
        int currDegree = HASH_COUNT(adj[i]);
        int parent = -1;
        int parentDegree = INT_MAX;

        /* 根据 degree 的大小找到当前节点的父节点 */
        HashEntry *curr = NULL, *next = NULL;
        HASH_ITER(hh, adj[i], curr, next) {
            if (HASH_COUNT(adj[curr->key]) < parentDegree && HASH_COUNT(adj[curr->key]) >= currDegree) {
                parent = curr->key;
                parentDegree = HASH_COUNT(adj[curr->key]);
            }
        }
        if (parent == -1) {
            return 0;
        }
        
        /* 检测 adj[node] 是否是 adj[parent] 的子集 */
        HASH_ITER(hh, adj[i], curr, next) {
            if (curr->key == parent) {
                continue;
            }
            if (!hashFind(&adj[parent], curr->key)) {
                return 0;
            }
        }
        if (parentDegree == currDegree) {
            res = 2;
        }
    }
    for (int i = 0; i < MAX_NODE_SIZE; i++) {
        hashFreeAll(&adj[i]);
    }
    return res;
}