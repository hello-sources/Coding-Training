class Solution {
    public int[] missingTwo(int[] nums) {
        int size = nums.length + 2, sum = 0;
        for (int i : nums) sum += i;
        int diff = (1 + size) * size / 2 - sum;
        int flag = diff / 2;
        sum = 0;
        for (int i : nums) {
            if (i <= flag) sum += i;
        }
        int num1 = (1 + flag) * flag / 2 - sum;
        return new int[]{num1, diff - num1};
    }
}