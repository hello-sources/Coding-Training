class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int ans = 0;
        for (int num : arr1) {
            int cur = binary_search(arr2, num);
            boolean flag = true;
            if (cur < arr2.length) {
                flag &= arr2[cur] - num > d;
            }
            if (cur >= 1 && cur <= arr2.length + 1) {
                flag &= num - arr2[cur - 1] > d;
            }
            ans += flag ? 1 : 0;
        }
        return ans;
    }
    
    public int binary_search(int[] arr, int x) {
        int left = 0, right = arr.length - 1;
        if (arr[right] < x) return right + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}