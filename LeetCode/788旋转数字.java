class Solution {
    int nums[] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    boolean judge(int x) {
        int cmp = x, temp = 0, loc = 0;
        while (x > 0) {
            int last = x % 10;
            if (nums[last] == -1) return false;
            temp += nums[last] * Math.pow(10, loc);
            loc++;
            x /= 10;
        }
        return cmp != temp;
    }

    public int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (judge(i)) ans++;
        }
        return ans;
    }
}