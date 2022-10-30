class Solution {
    public int strStr(String haystack, String needle) {
        int[] next = new int[needle.length()];
        getNext(needle, next);
        int j = 0;
        for (int i = 0; i < haystack.length(); i++) {
            while (j > 0 && needle.charAt(j) != haystack.charAt(i)) {
                j = next[j - 1];
            }
            if (needle.charAt(j) == haystack.charAt(i)) j++;
            if (j == needle.length()) {
                return  i - j + 1;
            }
        }
        return -1;
    }

    public void getNext(String s, int[] next) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = next[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) j++;
            next[i] = j;
        }
    }
}