class Solution {
public:
    bool judge(const string &str) {
        string s = str;
        reverse(s.begin(), s.end());
        return s == str;
    }

    void backtracking(string s, int ind) {
        if (ind == s.size()) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i < s.size(); i++) {
            string str = s.substr(ind, i - ind + 1);
            if (!judge(str)) continue;
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