class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int[] res = new int[queries.length];
        Arrays.sort(nums);
        for (int i = 0; i < queries.length; i++) {
            int cnt = 0, sum = 0;
            for (int j = 0; j < nums.length; j++) {
                sum += nums[j];
                if (sum <= queries[i]) cnt++;
                else break;
            }
            res[i] = cnt;
        }
        return res;
    }
}