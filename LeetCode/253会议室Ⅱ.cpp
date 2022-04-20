class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &i : intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }
        int cur = 0, ans = 0;
        for (auto &[left, right] : m) {
            cur += right;
            ans = max(ans, cur);
        }
        return ans;
    }
};