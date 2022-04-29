/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int count;
void dfs(int* nums,int numsSize,int depth,int* cur,bool* used,int** res){
    if(depth == numsSize){
        res[count] = (int *)malloc(numsSize * sizeof(int));
        memcpy(res[count++], cur, numsSize * sizeof(int));
        return;
    }
    for(int i = 0; i < numsSize; ++i){
        if(used[i] == true) continue;
        cur[depth] = nums[i];
        used[i] = true;
        dfs(nums, numsSize, depth+1, cur, used, res);
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 1;
    for(int i=1;i <= numsSize;++i) *returnSize *= i;
    int** res=(int **)malloc(1000 * sizeof(int *));
    bool* used=(bool *)malloc(numsSize * sizeof(bool));
    memset(used, 0, numsSize * sizeof(bool));
    int* cur=(int *)malloc(numsSize * sizeof(int));
    count = 0;
    dfs(nums, numsSize, 0, cur, used, res);
    *returnColumnSizes=(int *)malloc((*returnSize) * sizeof(int));
    for(int i = 0; i < *returnSize; ++i) (*returnColumnSizes)[i] = numsSize;
    return res;
}

/**********************C++********************/
class Solution {
public:
    void backtracking(vector<int> &nums, int ind, int size) {
        if (ind == nums.size()) {
            ans.emplace_back(nums);
            return ;
        }
        for (int i = ind; i < size; i++) {
            swap(nums[ind], nums[i]);
            backtracking(nums, ind + 1, size);
            swap(nums[ind], nums[i]);
        }
        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums, 0, nums.size());
        return ans;
    }

private :
    vector<vector<int>> ans;
};