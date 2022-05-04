class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        unordered_map<int, int> u_map;
        for (int i = 0; i < cards.size(); i++) {
            if (u_map[cards[i]]) {
                ans = min(ans, i + 1 - u_map[cards[i]] + 1);
                u_map[cards[i]] = i + 1;
            } else u_map[cards[i]] = i + 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};