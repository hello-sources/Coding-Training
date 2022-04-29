class Solution {
public:
    void backtracking(vector<int> &nums, int ind, vector<int> &used) {
        ans.emplace_back(temp);
        if (ind >= nums.size()) return ;
        for (int i = ind; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            temp.emplace_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};