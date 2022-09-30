class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> set_rols = new HashSet<>();
        Set<Integer> set_columns = new HashSet<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] != 0) continue;
                set_rols.add(i);
                set_columns.add(j);
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            if (!set_rols.contains(i)) continue;
            for (int j = 0; j < matrix[0].length; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].length; i++) {
            if (!set_columns.contains(i)) continue;
            for (int j = 0; j < matrix.length; j++) {
                matrix[j][i] = 0;
            }
        }
        return ;
    }
}