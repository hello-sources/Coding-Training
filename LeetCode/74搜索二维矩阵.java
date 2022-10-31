class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = binarySearch(matrix, target);
        if (row < 0) return false;
        return binarySearch_target(matrix[row], target);
    }

    public int binarySearch(int[][] matrix, int target) {
        int left = -1, right = matrix.length - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (matrix[mid][0] <= target) left = mid;
            else right = mid - 1;
        }
        return left;
    }

    public boolean binarySearch_target(int []matrix, int target) {
        int left = 0, right = matrix.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid] == target) return true;
            else if (matrix[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
}