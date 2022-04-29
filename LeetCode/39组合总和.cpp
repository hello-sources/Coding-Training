class Solution {
public:
    void backtracking(vector<int> &candidates, int target, int ind) {
        if (ind == candidates.size()) return ;
        if (target == 0) {
            ans.emplace_back(temp);
            return ;
        }
        backtracking(candidates, target, ind + 1);
        if (target - candidates[ind] >= 0) {
            temp.emplace_back(candidates[ind]);
            backtracking(candidates, target - candidates[ind], ind);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};