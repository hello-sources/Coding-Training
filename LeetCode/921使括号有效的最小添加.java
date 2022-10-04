class Solution {
    public int minAddToMakeValid(String s) {
        char[] chs = s.toCharArray();
        int cnt_left = 0, ans = 0;
        for (int i = 0; i < chs.length; i++) {
            if (chs[i] == '(') cnt_left++;
            else {
               if (cnt_left > 0) cnt_left--;
               else ans++;
            }
        }
        return ans + cnt_left;
    }
}