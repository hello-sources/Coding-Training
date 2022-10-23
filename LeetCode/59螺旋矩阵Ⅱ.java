class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int left = 0, right = n - 1, top = 0, buttom = n - 1;
        int num = 1;
        while (left <= right && top <= buttom) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = num;
                num++;
            }
            top++;
            for (int i = top; i <= buttom; i++) {
                ans[i][right] = num;
                num++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                ans[buttom][i] = num;
                num++;
            }
            buttom--;
            for (int i = buttom; i >= top; i--) {
                ans[i][left] = num;
                num++;
            }
            left++;
        }
        return ans;
    }
}