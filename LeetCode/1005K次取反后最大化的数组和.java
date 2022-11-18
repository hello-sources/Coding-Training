class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        for (int v : nums) list.add(v);
        list.sort((a, b) -> Math.abs(a) - Math.abs(b));
        int ans = 0;
        for (int i = list.size() - 1; i >= 0; i--) {
            if (list.get(i) < 0 && k > 0) {
                k--;
                ans += -list.get(i);
            } else {
                ans += list.get(i);
            }
        }
        if (k % 2 == 1) ans -= 2 * Math.abs(list.get(0));
        return ans;
    }
}