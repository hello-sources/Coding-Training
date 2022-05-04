class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else {
                left--;
                if (s[i - 1] == '(') ans += 1 << left;
            }
        }
        return ans;
    }
};