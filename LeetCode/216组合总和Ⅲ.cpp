class Solution {
public:
    void backtracking(int k, int n, int ind) {
        if (0 == n && temp.size() == k) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i <= 9; i++) {
            temp.emplace_back(i);
            backtracking(k, n - i, i + 1);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};