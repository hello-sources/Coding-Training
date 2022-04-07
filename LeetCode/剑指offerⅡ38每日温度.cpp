class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> sta;
        for (auto i = 0; i < temperatures.size(); i++) {
            while (!sta.empty() && temperatures[sta.top()] < temperatures[i]) {
                //res.push_back(i - sta.top());
                res[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }
        return res;
    }
};