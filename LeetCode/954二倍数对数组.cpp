typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} Hash;

int cmp(const void *a, const void *b) {
    int pa = *(int *)a;
    int pb = *(int *)b;
    return abs(pa) - abs(pb);
}

bool canReorderDoubled(int* arr, int arrSize){
    Hash *g_hash = NULL, *temp;
    for (int i = 0; i < arrSize; i++) {
        temp = NULL;
        HASH_FIND_INT(g_hash, &arr[i], temp);
        if (temp == NULL) {
            temp = (Hash *)malloc(sizeof(Hash));
            temp->val = 1;
            temp->key = arr[i];
            HASH_ADD_INT(g_hash, key, temp);
        } else {
            temp->val++;
        }
    }
    temp = NULL;
    int key = 0;
    HASH_FIND_INT(g_hash, &key, temp);
    if (temp != NULL && temp->val % 2) return false;
    int cnt = HASH_COUNT(g_hash);
    int *val = (int *)malloc(sizeof(int) * cnt);
    int ind = 0;
    Hash *temp2;
    HASH_ITER(hh, g_hash, temp, temp2) {
        val[ind++] = temp->key;
    }
    qsort(val, cnt, sizeof(int), cmp);
    for (int i = 0; i < cnt; i++) {
        int c1 = 0, c2 = 0;
        int key = val[i];
        Hash *item1 = NULL, *item2 = NULL;
        HASH_FIND_INT(g_hash, &key, item1);
        if (item1) {
            c1 = item1->val;
        }
        key = 2 * val[i];
        HASH_FIND_INT(g_hash, &key, item2);
        if (item2) {
            c2 = item2->val;
        }
        if (c1 > c2) return false;
        if (item2) item2->val -= c1;
    }
    HASH_ITER(hh, g_hash, temp, temp2) {
        HASH_DEL(g_hash, temp);
        free(temp);
    }
    free(val);
    return true;
}