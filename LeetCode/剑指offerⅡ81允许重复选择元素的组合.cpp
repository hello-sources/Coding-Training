class Solution {
public:
    void backtracking(int ind, int sum, int target, vector<int> &candidates) {
        if (sum == target) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            temp.emplace_back(candidates[i]);
            backtracking(i, sum, target, candidates);
            sum -= candidates[i];
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, target, candidates);
        return ans;
    }
private :
    vector<vector<int>> ans;
    vector<int> temp;
};