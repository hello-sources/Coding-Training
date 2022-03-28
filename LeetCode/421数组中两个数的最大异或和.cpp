struct Hash{
    int key;
    UT_hash_handle hh;
} ;

int findMaximumXOR(int* nums, int numsSize){
    int x = 0;
    for (int k = 30; k >= 0; k--) {
        struct Hash *hash = NULL;
        for (int i = 0; i < numsSize; i++) {
            int x = nums[i] >> k;
            struct Hash *temp;
            HASH_FIND_INT(hash, &x, temp);
            if (temp == NULL) {
                temp = malloc(sizeof(struct Hash));
                temp->key = x;
                HASH_ADD_INT(hash, key, temp);
            }
        }
        int x_next = 2 * x + 1;
        bool flag = false;
        for (int j = 0; j < numsSize; j++) {
            int x = x_next ^ (nums[j] >> k);
            struct Hash *temp;
            HASH_FIND_INT(hash, &x, temp);
            if (temp != NULL) {
                flag = true;
                break;
            }
        }
        if (flag) {
            x = x_next;
        } else {
            x = x_next - 1;
        }
    }
    return x;
}