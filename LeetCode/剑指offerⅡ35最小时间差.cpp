class Solution {
public:
    int get_min(string str) {
        return ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + (str[4] - '0');
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int pre = get_min(timePoints[0]);
        int now = pre;
        for (int i = 1; i < timePoints.size(); i++) {
            int temp = get_min(timePoints[i]);
            ans = min(ans, temp - pre);
            pre = temp;
        }
        ans = min(ans, now + 1440 - pre);
        return ans;
    }
};