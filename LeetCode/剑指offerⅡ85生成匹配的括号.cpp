class Solution {
public:
    void backtracking(int left, int right, int n) {
        if (n * 2 == temp.size()) {
            ans.push_back(temp);
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