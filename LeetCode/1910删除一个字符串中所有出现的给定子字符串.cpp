class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        string str;
        for (auto x : s) {
            str.push_back(x);
            int n = str.size();
            if (n >= m && str.substr(n - m, n) == part) {
                str = str.substr(0, n - m);
            }
        }
        return str;
    }
};