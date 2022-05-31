class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> u_map, u_map1;
        for (auto x : target) {
            u_map[x]++;
        }
        for (auto x : s) {
            u_map1[x]++;
        }
        int ans = INT_MAX;
        for (auto x : target) {
            ans = min(ans, u_map1[x] / u_map[x]);
        }
        return ans;
    }
};