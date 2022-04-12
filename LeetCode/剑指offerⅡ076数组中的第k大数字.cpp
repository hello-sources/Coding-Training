class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> prq;
        for (auto &x : nums) {
            prq.push(x);
        }
        while (--k) {
            prq.pop();
        }
        return prq.top();
    }
};