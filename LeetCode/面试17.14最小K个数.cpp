class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> prq;
        for (auto &x : arr) {
            prq.push(x);
        }
        vector<int> res;
        while (k--) {
            res.push_back(prq.top());
            prq.pop();
        }
        return res;
    }
};