class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans;
        string temp1;
        for (int i = 0; i < number.size(); i++) {
            string temp;
            if (digit == number[i]) {
                temp = number.substr(0, i) + number.substr(i + 1);
            }    
            ans = max(ans, temp);
        }
        return ans;
    }
};