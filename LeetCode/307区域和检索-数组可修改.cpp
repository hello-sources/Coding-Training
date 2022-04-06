/*********************超时*********************/
typedef struct {
    int *nums;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->nums = nums;
    obj->size = numsSize;
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    obj->nums[index] = val;
    return ;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int ans = 0;
    while (left <= right) ans += obj->nums[left++];
    return ans;
}

void numArrayFree(NumArray* obj) {
    free(obj);
    return ;
}

/**********************树状数组*****************/
static int lowbit(int x) {
    return x & (-x);
}

static void Fenupdate(int *arr, int len, int i, int add) {
    while (i < len) {
        arr[i] += add;
        i += lowbit(i);
    }
    return ;
}

static int Fenquery(int *arr, int i) {
    int sum = 0;
    while (i > 0) {
        sum += arr[i];
        i -= lowbit(i);
    }
    return sum;
}

typedef struct {
    int *arr, *old;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->old = nums;
    obj->arr = (int *)calloc(1, sizeof(int) * (numsSize + 1));
    obj->size = numsSize + 1;
    for (int i = 0; i < numsSize; i++) {
        Fenupdate(obj->arr, obj->size, i + 1, nums[i]);
    }
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    Fenupdate(obj->arr, obj->size, index + 1, val - obj->old[index]);
    obj->old[index] = val;
    return ;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int l, r;
    l = Fenquery(obj->arr, left);
    r = Fenquery(obj->arr, right + 1);
    return r - l;
}

void numArrayFree(NumArray* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/