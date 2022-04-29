class Solution {
public:
    void backtracking(int ind, string digits) {
        if (digits.size() == 0) return ;
        if (ind == digits.size()) {
            ans.emplace_back(temp);
            return ;
        }
        string str = u_map[digits[ind]];
        for (int i = 0; i < str.size(); i++) {
            temp.push_back(str[i]);
            backtracking(ind + 1, digits);
            temp.pop_back();
        }
        return ;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> button = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (auto digit : digits) u_map[digit] = button[digit - '2'];
        backtracking(0, digits);
        return ans;
    }

private :
    vector<string> ans;
    string temp;
    unordered_map<char, string> u_map;
};