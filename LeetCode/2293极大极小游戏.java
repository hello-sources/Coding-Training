class Solution {
    public int minMaxGame(int[] nums) {
        int length = nums.length;
        if (length == 1) return nums[0];
        int[] arr = {};
        while (length > 1) {
            length /= 2;
            arr = new int[length];
            for (int i = 0; i < length; i++) {
                if (i % 2 == 0) arr[i] = Math.min(nums[2 * i], nums[2 * i + 1]);
                else if (i % 2 == 1) arr[i] = Math.max(nums[2 * i], nums[2 * i + 1]);
            }
            for (int i = 0; i < length; i++) nums[i] = arr[i];
        }
        return arr[0];
    }
}