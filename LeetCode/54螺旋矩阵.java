class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        List<Integer> ans = new ArrayList<>();
        int left = 0, right = n - 1;
        int top = 0, buttom = m - 1;
        int num = m * n;
        while (num > 0) {
            for (int i = left; i <= right && num >= 1; i++) {
                ans.add(matrix[top][i]);
                num--;
            }
            top++;
            for (int i = top; i <= buttom && num >= 1; i++) {
                ans.add(matrix[i][right]);
                num--;
            }
            right--;
            for (int i = right; i >= left && num >= 1; i--) {
                ans.add(matrix[buttom][i]);
                num--;
            }
            buttom--;
            for (int i = buttom; i >= top && num >= 1; i--) {
                ans.add(matrix[i][left]);
                num--;
            }
            left++;
        }
        return ans;
    }
}