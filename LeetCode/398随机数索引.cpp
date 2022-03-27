typedef struct {
    int *nums;
    int size;
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->nums = nums;
    obj->size = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    while (true) {
        int ind = rand() % obj->size;
        if (obj->nums[ind] == target) return ind;
    }
    return -1;
}

void solutionFree(Solution* obj) {
    free(obj->nums);
    free(obj);
    return ;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 
 * solutionFree(obj);
*/

/*************************UT_hash做法*************************/
typedef struct {
    int key, cnt;
    int index[50];
    UT_hash_handle hh;
} Hash;

typedef struct {
    Hash *g_hash;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->g_hash = NULL;
    for (int i = 0; i < numsSize; i++) {
        Hash *temp = NULL;
        HASH_FIND_INT(obj->g_hash, &nums[i], temp);
        if (temp == NULL) {
            temp = (Hash *)malloc(sizeof(Hash));
            temp->key = nums[i];
            temp->index[0] = i;
            temp->cnt = 1;
            HASH_ADD_INT(obj->g_hash, key, temp);
        } else {
            temp->index[temp->cnt++] = i;
        }
    }
    return obj;
}

int solutionPick(Solution* obj, int target) {
    Hash *temp = NULL;
    HASH_FIND_INT(obj->g_hash, &target, temp);
    return temp->index[rand() % temp->cnt];
}

void solutionFree(Solution* obj) {
    Hash *cur, *temp;
    HASH_ITER(hh, obj->g_hash, cur, temp) {
        if (cur != NULL) {
            HASH_DEL(obj->g_hash, cur);
            free(cur);
        }
    }
    return ;
}