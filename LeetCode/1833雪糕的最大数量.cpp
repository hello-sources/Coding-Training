class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (auto x : costs) {
            if (x > coins) break;
            coins -= x;
            cnt++;
        }
        return cnt;
    }
};