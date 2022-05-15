class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int len = str.size(), ans = 0;
        for (int i = 0; i + k <= len; i++) {
            int cur = stoi(str.substr(i, k));
            if (cur != 0 && num % cur == 0) ans++;
        }
        return ans;
    }
};