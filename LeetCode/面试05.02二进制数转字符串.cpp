class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (num != 0) {
            num *= 2;
            if (num >= 1) {
                ans += '1';
                num -= 1;
            } else {
                ans += '0';
            }
        }
        if (ans.size() > 32) return "ERROR";
        return ans;
    }
};