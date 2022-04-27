class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int ans = 0;
        for (int i = 0; i < fruits.size(); i++) {
            int cnt = (fruits[i][1] % limit == 0) ? (fruits[i][1] / limit) : (fruits[i][1] / limit + 1);
            ans += cnt * time[fruits[i][0]];
        }
        return ans;
    }
};