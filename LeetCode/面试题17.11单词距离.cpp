class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            u_map[words[i]].emplace_back(i);
        }
        auto vec1 = u_map[word1];
        auto vec2 = u_map[word2];
        for (int i = 0; i < vec1.size(); i++) {
            for (int j = 0; j < vec2.size(); j++) {
                ans = min(ans, abs(vec2[j] - vec1[i]));
            }
        }
        return ans;
    }

private :
    unordered_map<string, vector<int>> u_map;
};