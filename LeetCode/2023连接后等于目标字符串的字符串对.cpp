class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (j == i) continue;
                string temp = nums[i];
                temp += nums[j];
                if (target.compare(temp) == 0) ans++;
            }
        }
        return ans;
    }
};