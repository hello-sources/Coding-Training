class Solution {
public:
    void backtracking(int ind, vector<int> &nums, vector<bool> &used) {
        ans.emplace_back(temp);
        if (temp.size() > nums.size()) return ;
        for (int i = ind; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && nums[i - 1] == false) continue;
            if (used[i]) continue;
            used[i] = true;
            temp.emplace_back(nums[i]);
            backtracking(i + 1, nums, used);
            used[i] = false;
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(0, nums, used);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};