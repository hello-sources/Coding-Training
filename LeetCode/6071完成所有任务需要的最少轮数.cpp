class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        int ans = 0;
        for (auto &x : tasks) m[x]++;
        for (auto i = m.begin(); i != m.end(); i++) {
            int temp = i->second;
            if (temp == 1) return -1;
            else if (temp == 2) ans++;
            else if (temp % 3 == 0) ans += temp / 3;
            else ans += temp / 3 + 1;
        }
        return ans;
    }
};