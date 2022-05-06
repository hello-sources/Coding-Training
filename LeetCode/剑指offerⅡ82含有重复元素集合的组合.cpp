class Solution {
public:
    void backtracking(vector<int> &candidates, vector<bool> &used, int ind, int target) {
        if (target == 0) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i < candidates.size() && candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            used[i] = true;
            target -= candidates[i];
            temp.emplace_back(candidates[i]);
            backtracking(candidates, used, i + 1, target);
            target += candidates[i];
            used[i] = false;
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, used, 0, target);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};