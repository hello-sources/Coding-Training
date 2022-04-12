class Solution {
public:
    const int mod = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> prq;
        for (auto &x : nums) {
            prq.push(x);
        }
        while (k--) {
            int temp = prq.top();
            prq.pop();
            temp += 1;
            prq.push(temp);
        }
        long ans = 1;
        while (!prq.empty()) {
            ans *= prq.top();
            prq.pop();
            ans %= mod;
        }
        return ans;
    }
};