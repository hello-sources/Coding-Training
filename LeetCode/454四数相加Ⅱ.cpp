class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> u_map;
        for (int a : nums1) {
            for (int b : nums2) {
                u_map[a + b]++;
            }
        }
        for (int a : nums3) {
            for (int b : nums4) {
                int sum = 0 - a - b;
                if (u_map[sum] != 0) {
                    ans += u_map[sum];
                }
            }
        }
        return ans;
    }
};