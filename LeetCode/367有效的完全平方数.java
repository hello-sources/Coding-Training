class Solution {
    public boolean isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long temp = (long)mid * mid;
            if (temp == num) return true;
            else if (temp < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } 
        return false;
    }
}