class Solution {
public:
    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (temp.size() == nums.size()) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;
            if (used[i]) continue;
            temp.emplace_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return ans;
    }
private :
    vector<vector<int>> ans;
    vector<int> temp;
};