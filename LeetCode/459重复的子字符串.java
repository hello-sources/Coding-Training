class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        int[] next = new int[len];
        getNext(s, next);
        if (next[len - 1] > 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
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