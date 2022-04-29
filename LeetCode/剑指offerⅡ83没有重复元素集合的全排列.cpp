class Solution {
public:
    void backtracking(vector<int> &nums, int ind, int size) {
        if (ind == size) {
            ans.emplace_back(nums);
        }
        for (int i = ind; i < size; i++) {
            swap(nums[i], nums[ind]);
            backtracking(nums, ind + 1, size);
            swap(nums[i], nums[ind]);
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