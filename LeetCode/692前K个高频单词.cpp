class Solution {
public:
    struct cmp {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> u_map;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> prq;
        for (auto &x : words) u_map[x]++;
        for (auto &x : u_map) {
            prq.emplace(x);
            if (prq.size() > k) prq.pop();
        }
        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = prq.top().first;
            prq.pop();
        }
        return res;
    }
};