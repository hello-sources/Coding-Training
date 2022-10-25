class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int left = 1, right = arr.length - 2;
        int ind = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                ind = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ind;
    }
}