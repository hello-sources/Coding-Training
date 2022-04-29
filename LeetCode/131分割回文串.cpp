class Solution {
public:
    bool is_rev(const string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    void backtracking(string s, int ind) {
        if (ind == s.size()) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i < s.size(); i++) {
            if (!is_rev(s, ind, i)) continue;
            string str = s.substr(ind, i - ind + 1);
            temp.emplace_back(str);
            backtracking(s, i + 1);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
private :
    vector<vector<string>> ans;
    vector<string> temp;
};