class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> prq;
        for (auto &x : nums) {
            if (prq.size() < k) prq.emplace(x);
            else {
                if (x > prq.top()) {
                    prq.emplace(x);
                    prq.pop();
                    
                }
            }
        }
        return prq.top();
    }
};