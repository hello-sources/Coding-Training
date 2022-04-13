class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() < 2) return nums;
        unordered_map<int, int> u_map;
        priority_queue<pair<int, int>> prq;
        for (auto &x : nums) u_map[x]++;
        for (auto &x : u_map) {
            prq.push({x.second, x.first});
        }
        vector<int> vec;
        while (k--) {
            vec.push_back(prq.top().second);
            prq.pop();
        }
        return vec;
    }
};