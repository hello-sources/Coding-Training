class Solution {
public:
    // vector<int> sortArray(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums;
    // }
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> prq;
        for (auto &x : nums) prq.push(x);
        vector<int> res;
        while (!prq.empty()) {
            res.push_back(prq.top());
            prq.pop();
        }
        return res;
    }
};