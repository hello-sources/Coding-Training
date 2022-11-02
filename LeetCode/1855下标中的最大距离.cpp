class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int left = i, right = nums2.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums1[i] <= nums2[mid]) {
                    left = mid + 1;
                    ans = max(ans, mid - i);
                } else {
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};