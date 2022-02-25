typedef struct {
    int *nums;
    int numsSize;
} MRUQueue;

MRUQueue* mRUQueueCreate(int n) {
    MRUQueue *obj = (MRUQueue *)malloc(sizeof(MRUQueue));
    obj->nums = (int *)malloc(sizeof(int) * (n + 5));
    obj->numsSize = n;
    for (int i = 0; i < n; i++) {
        obj->nums[i] = i + 1;
    }
    return obj;
}

int mRUQueueFetch(MRUQueue* obj, int k) {
    int temp = obj->nums[k - 1];
    for (int i = k - 1; i < obj->numsSize; i++) {
        obj->nums[i] = obj->nums[i + 1];
    }
    obj->nums[obj->numsSize - 1] = temp;
    return temp;
}

void mRUQueueFree(MRUQueue* obj) {
    if (obj == NULL) return ;
    free(obj->nums);
    free(obj);
    return ;
}

/**
 * Your MRUQueue struct will be instantiated and called as such:
 * MRUQueue* obj = mRUQueueCreate(n);
 * int param_1 = mRUQueueFetch(obj, k);
 
 * mRUQueueFree(obj);
*/