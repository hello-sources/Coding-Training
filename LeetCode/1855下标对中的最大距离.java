class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.length; i++) {
            int left = i + 1, right = nums2.length - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums1[i] <= nums2[mid]) {
                    left = mid + 1;
                    ans = Math.max(ans, mid - i);
                } else {
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
}