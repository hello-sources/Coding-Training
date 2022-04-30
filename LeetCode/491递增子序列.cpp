class Solution {
public:
    void backtracking(vector<int> &nums, int ind) {
        if (temp.size() > 1) ans.emplace_back(temp);
        unordered_set<int> u_set;
        for (int i = ind; i < nums.size(); i++) {
            if ((!temp.empty() && nums[i] < temp.back()) || u_set.find(nums[i]) != u_set.end()) continue;
            u_set.insert(nums[i]);
            temp.emplace_back(nums[i]);
            backtracking(nums, i + 1);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);    
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};