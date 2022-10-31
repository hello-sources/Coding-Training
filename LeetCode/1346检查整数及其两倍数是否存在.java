class Solution {
    public boolean checkIfExist(int[] arr) {
        Arrays.sort(arr);
        for (int i = 0; i < arr.length - 1; i++) {
            int left = 0, right = arr.length - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int val1 = arr[mid], val2 = arr[i] * 2;
                if(val1 == val2 && mid != i) return true; 
                else if(val2 < val1) right = mid - 1;
                else left = mid + 1; 
            }
        }
        return false;
    }
}