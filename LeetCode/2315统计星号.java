class Solution {
    public int countAsterisks(String s) {
        int res = 0, cnt = 0;
        char[] chs = s.toCharArray();
        for (char ch : chs) {
            if (ch == '*' && cnt == 0) res++;
            if (ch == '|') {
                cnt += 1;
                cnt %= 2;
            }
        }
        return res;
    }
}