class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string tmp = {num[i], num[i], num[i]};
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};