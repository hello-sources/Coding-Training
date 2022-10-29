class Solution {
    public String reverseStr(String s, int k) {
        char[] chs = s.toCharArray();
        for (int i = 0; i < chs.length; i += 2 * k) {
            int left = i;
            int right = Math.min(left + k - 1, chs.length - 1);
            while (left < right) {
                chs[left] ^= chs[right];
                chs[right] ^= chs[left];
                chs[left] ^= chs[right];
                left++;
                right--;
            }
        }
        return new String(chs);
    }
}