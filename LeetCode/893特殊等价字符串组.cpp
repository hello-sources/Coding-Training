class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> u_set;
        for (auto &word : words) {
            string odd, even;
            for (int i = 0; i < word.size(); i++) {
                if (i & 1) odd.push_back(word[i]);
                else even.push_back(word[i]);
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            string trick = odd + "&" + even;
            u_set.emplace(trick);
        }
        return u_set.size();
    }
};