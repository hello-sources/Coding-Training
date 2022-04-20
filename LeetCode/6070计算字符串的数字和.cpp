class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp;
            int sum = 0;
            for (int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';
                if (i % k == k - 1 || i == s.size() - 1) {
                    temp += to_string(sum);
                    sum = 0;
                }
            }
            s = temp;
        }
        return s;
    }
};