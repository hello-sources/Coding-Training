class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int, int>> prq;
        unordered_map<int, int> u_map;
        for (auto &x : arr) u_map[x]++;
        for (auto &x : u_map) {
            prq.push({x.second, x.first});
        }
        int cnt = 0, ans = 0;
        while (cnt < arr.size() / 2) {
            cnt += prq.top().first;
            ans++;
            prq.pop();
        }
        return ans;
    }
};