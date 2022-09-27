class Solution {
    public boolean checkXMatrix(int[][] grid) {
        int cnt = grid.length - 1;
        for (int i = 0; i < grid.length; i++) {
            if (grid[i][i] == 0) return false;
            if (grid[cnt--][i] == 0) return false;
        }
        cnt = grid.length - 1;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (i == j || i + j == cnt) continue;
                if (grid[i][j] != 0) return false;
            }
        }
        return true;
    }
}