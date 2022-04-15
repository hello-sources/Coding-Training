class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> u_map;
        for (auto &x : strs) {
            string str = x;
            sort(str.begin(), str.end());
            u_map[str].emplace_back(x);
        }
        vector<vector<string>> ans;
        for (auto iter = u_map.begin(); iter != u_map.end(); iter++) {
            ans.emplace_back(iter->second);
        }
        return ans;
    }
};