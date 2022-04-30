class Solution {
public:
    void backtracking(int left, int right, int n) {
        if (temp.size() == 2 * n) {
            ans.emplace_back(temp);
            return ;
        }
        if (left < n) {
            temp.push_back('(');
            backtracking(left + 1, right, n);
            temp.pop_back();
        }
        if (right < left) {
            temp.push_back(')');
            backtracking(left, right + 1, n);
            temp.pop_back();
        }
        return ;
    }

    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n);
        return ans;
    }

private :
    vector<string> ans;
    string temp;
};