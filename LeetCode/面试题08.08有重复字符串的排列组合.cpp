class Solution {
public:
    void backtracking(string s, vector<bool> &used) {
        if (temp.size() == s.size()) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1] && used[i - 1] == false) continue;
            if (used[i] == true) continue;
            used[i] = true;
            temp.push_back(s[i]);
            backtracking(s, used);
            used[i] = false;
            temp.pop_back();
        }
        return ;
    }

    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        vector<bool> used(S.size(), false);
        backtracking(S, used);
        return ans;
    }

private :
    vector<string> ans;
    string temp;
};