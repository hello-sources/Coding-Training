class Solution {
    public int countNegatives(int[][] grid) {
        int cnt = 0;
        for (int i = 0; i < grid.length; i++) {
            int left = 0, right = grid[i].length - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[i][mid] >= 0) left = mid + 1;
                else right = mid - 1;
            }
            cnt += grid[i].length - left; 
        }
        return cnt;
    }
}