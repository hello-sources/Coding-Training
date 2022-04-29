class Solution {
public:
    void backtracking(vector<int> &candidates, int target, int sum, int ind, vector<bool> &used) {
        // if (ind == candidates.size()) return ;
        if (target == sum) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i < candidates.size() && target - candidates[i] >= sum; i++) {
            if (i > 0 &&  candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            sum += candidates[i];
            temp.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};