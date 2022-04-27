/*************************暴力超时**********************************/
int reversePairs(int* nums, int numsSize){
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) ans++;
        }
    }
    return ans;
}

/***************************归并排序*************************/
int merge_sort(int left, int right, int *nums, int *temp) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int res = merge_sort(left, mid, nums, temp) + merge_sort(mid + 1, right, nums, temp);
    for (int k = left; k <= right; k++) {
        temp[k] = nums[k];
    }
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i == mid + 1) nums[k] = temp[j++];
        else if (j == right + 1 || temp[i] <= temp[j]) nums[k] = temp[i++];
        else {
            nums[k] = temp[j++];
            res += mid - i + 1;
        }
    }
    return res;
}

int reversePairs(int* nums, int numsSize){
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    return merge_sort(0, numsSize - 1, nums, temp);
}

/*************************离散化树状数组****************************/
class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int size) {
        while (x < size) {
            C[x]++;
            x += lowbit(x);
        }
        return ;
    }

    int query(int x, int size) {
        int sum = 0;
        while (x) {
            sum += C[x];
            x -= lowbit(x);
        }
        return sum;
    }

    void discretization(vector<int> &nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        return ;
    }

    int reversePairs(vector<int>& nums) {
        int sum = 0, ans = 0;
        int size = nums.size();
        C.resize(size);
        discretization(nums);
        for (auto &num : nums) {
            num = lower_bound(a.begin(), a.end(), num) - a.begin() + 1;
        }
        for (int i = size - 1; i >= 0; i--) {
            ans += query(nums[i] - 1, size);
            update(nums[i], size);
        }
        return ans;
    }

private :
    vector<int> C;
    vector<int> a;
};