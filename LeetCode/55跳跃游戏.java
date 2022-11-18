class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        for (int i = 1; i < prices.length; i++) {
            ans += Math.max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
}

/**
 * 每到一个位置到底往前走几步这个可以不需要考虑
 * 从每个位置的覆盖范围来考虑，如果一个点的覆盖范围超过了数组长度，那么就可以跳跃完成的
 * 问题及转化为每一个点跳跃范围，如果跳跃范围大与数组长度的话，视为成功
 */