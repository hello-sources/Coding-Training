class Solution {
    typedef pair<int, string> pii;
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pii> vec;
        for (int i = 0; i < names.size(); i++) vec.push_back(pii(heights[i], names[i]));
        sort(vec.begin(), vec.end());
        vector<string> ans;
        // for (pii p : vec) ans.push_back(p.second);
        for (int i = vec.size() - 1; i >= 0; i--) ans.push_back(vec[i].second);
        return ans;
    }
};