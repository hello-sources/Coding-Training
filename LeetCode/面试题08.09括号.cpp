class Solution {
public:
    void backtracking(int l, int r, int n) {
        if (temp.size() == n * 2) {
            ans.emplace_back(temp);
            return ;
        }
        if (l < n) {
            temp.push_back('(');
            backtracking(l + 1, r, n);
            temp.pop_back();
        }
        if (r < l) {
            temp.push_back(')');
            backtracking(l, r + 1, n);
            temp.pop_back();
        }
        return ;
    }

    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n);
        return ans;
    }

private:
    vector<string> ans;
    string temp;
};