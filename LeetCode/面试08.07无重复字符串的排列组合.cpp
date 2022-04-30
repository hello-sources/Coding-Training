class Solution {
public:
    void backtracking(int ind, string s, vector<bool> &used) {
        if (temp.size() == s.size()) {
            ans.push_back(temp);
            return ;
        }
        for (int i = 0; i < s.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            temp.push_back(s[i]);
            backtracking(i + 1, s, used);
            used[i] = false;
            temp.pop_back();
        }
        return ;
    }

    vector<string> permutation(string s) {
        vector<bool> used(s.size(), false);
        backtracking(0, s, used);
        return ans;
    }

private:
    vector<string> ans;
    string temp;
};