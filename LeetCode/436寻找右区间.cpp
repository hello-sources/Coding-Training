class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < intervals.size(); i++) {
            nums.emplace_back(intervals[i][0], i);
        }
        sort(nums.begin(), nums.end());
        ans.resize(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); i++) {
            auto iter = lower_bound(nums.begin(), nums.end(), make_pair(intervals[i][1], 0));
            if (iter != nums.end()) {
                ans[i] = iter->second;
            }
        }
        return ans;
    }

private :
    vector<int> ans;
};