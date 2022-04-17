class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> ans(3);
        priority_queue<pair<int, int>> prq;
        prq.emplace(memory1, -1);
        prq.emplace(memory2, -2);
        int time = 1;
        while (!prq.empty()) {
            auto [v, ind] = prq.top();
            prq.pop();
            if (v < time) {
                auto[v2, ind2] = prq.top();
                prq.pop();
                ans[abs(ind)] = v;
                ans[abs(ind2)] = v2;
                ans[0] = time;
                return ans;
            }
            prq.emplace(v - time, ind);
            time++;
        }
        return ans;
    }
};