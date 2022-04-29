/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int len = 1 << numsSize;
    int **ans = (int **)malloc(sizeof(int *) * len);
    *returnColumnSizes = (int *)malloc(sizeof(int) * len);
    *returnSize = len;
    int cnt[numsSize];
    for (int i = 0; i < len; i++) {
        int size = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) cnt[size++] = nums[j];
        }
        int *temp = (int *)malloc(sizeof(int) * size);
        memcpy(temp, cnt, sizeof(int) * size);
        (*returnColumnSizes)[i] = size;
        ans[i] = temp;
    }
    return ans;
}

/************************C++*************************/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = 1 << nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < len; i++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) temp.push_back(nums[j]); 
            }
            res.push_back(temp);
        }
        return res;
    }
};

/*******************回溯***************************/
class Solution {
public:
    void backtracking(vector<int> &nums, int ind) {
        ans.emplace_back(temp);
        if (ind >= nums.size()) return ;
        for (int i = ind; i < nums.size(); i++) {
            temp.emplace_back(nums[i]);
            backtracking(nums, i + 1);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};