typedef struct hashTable {
    int key, val;
    UT_hash_handle hh;
} hashTable;

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    hashTable *h = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashTable *temp = NULL;
        HASH_FIND_INT(h, &nums[i], temp);
        if (temp == NULL) {
            temp = (hashTable *)malloc(sizeof(hashTable));
            temp->val = i;
            temp->key = nums[i];
            HASH_ADD_INT(h, key, temp);
        } else {
            if (i - temp->val <= k) return true;
            else temp->val = i;
        }
    }
    return false;
}