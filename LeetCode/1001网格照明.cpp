/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    long long key;
    int val;
    UT_hash_handle hh;
} HashEntry;

static inline long long hash(int x, int y) {
    return (long long) x + ((long long) y << 32);
}

void hashInsert(HashEntry ** obj, long long key) {
    HashEntry * pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(long long), pEntry);
    if (NULL == pEntry) {
        pEntry = (HashEntry *)malloc(sizeof(HashEntry));
        pEntry->key = key;
        pEntry->val = 1;
        HASH_ADD(hh, *obj, key, sizeof(long long), pEntry);
    } else {
        pEntry->val++;
    }
}

void hashErase(HashEntry ** obj, long long key) {
    HashEntry * pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(long long), pEntry);
    if (NULL != pEntry) {
        pEntry->val -= 1;
        if (pEntry->val == 0) {
            HASH_DEL(*obj, pEntry);
            free(pEntry);
        }
    }
}

void hashDelete(HashEntry ** obj, long long key) {
    HashEntry * pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(long long), pEntry);
    if (NULL != pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
    }
}

bool hashFind(HashEntry ** obj, long long key) {
    HashEntry * pEntry = NULL;
    HASH_FIND(hh, *obj, &key, sizeof(long long), pEntry);
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

int* gridIllumination(int n, int** lamps, int lampsSize, int* lampsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    HashEntry * row = NULL, * col = NULL;
    HashEntry * diagonal = NULL, * antiDiagonal = NULL;
    HashEntry * points = NULL;
    for (int i = 0; i < lampsSize; i++) {
        HashEntry * pEntry = NULL;
        long long p = hash(lamps[i][0], lamps[i][1]);
        HASH_FIND(hh, points, &p, sizeof(long long), pEntry);
        if (NULL != pEntry) {
            continue;
        }
        hashInsert(&points, p);
        hashInsert(&row, (long long)lamps[i][0]);
        hashInsert(&col, (long long)lamps[i][1]);
        hashInsert(&diagonal, (long long)(lamps[i][0] - lamps[i][1]));
        hashInsert(&antiDiagonal, (long long)(lamps[i][0] + lamps[i][1]));
    }

    int * ret = (int *)malloc(sizeof(int) * queriesSize);
    memset(ret, 0, sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int r = queries[i][0], c = queries[i][1];
        if (hashFind(&row, (long long)r)) {
            ret[i] = 1;
        } else if (hashFind(&col, (long long)c)) {
            ret[i] = 1;
        } else if (hashFind(&diagonal, (long long)(r - c))) {
            ret[i] = 1;
        } else if (hashFind(&antiDiagonal, (long long)(r + c))) {
            ret[i] = 1;
        }
        for (int x = r - 1; x <= r + 1; x++) {
            for (int y = c - 1; y <= c + 1; y++) {
                if (x < 0 || y < 0 || x >= n || y >= n) {
                    continue;
                }
                if (hashFind(&points, hash(x, y))) {
                    hashDelete(&points, hash(x, y));
                    hashErase(&row, (long long)x);
                    hashErase(&col, (long long)y);
                    hashErase(&diagonal, (long long)(x - y));
                    hashErase(&antiDiagonal, (long long)(x + y));
                }
            }
        }
    }
    hashFreeAll(&points);
    hashFreeAll(&row);
    hashFreeAll(&col);
    hashFreeAll(&diagonal);
    hashFreeAll(&antiDiagonal);
    *returnSize = queriesSize;
    return ret;
}