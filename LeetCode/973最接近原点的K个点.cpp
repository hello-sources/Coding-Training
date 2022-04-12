class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> prq;
        for (int i = 0; i < k; i++) {
            prq.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        for (int i = k; i < points.size(); i++) {
            int temp = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (temp < prq.top().first) {
                prq.pop();
                prq.emplace(temp, i);
            }
        }
        vector<vector<int>> res;
        int cnt = 0;
        while (!prq.empty()) {
            res.push_back(points[prq.top().second]);
            //res[cnt][0] = points[prq.top().second][0];
            //res[cnt++][1] = points[prq.top().second][1];
            prq.pop();
        }
        return res;
    }
};