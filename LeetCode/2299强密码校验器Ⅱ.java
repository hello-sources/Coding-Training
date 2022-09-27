import java.util.HashSet;

class Solution {
    public boolean strongPasswordCheckerII(String password) {
        if (password.length() < 8) return false;
        int cnt_big = 0, cnt_small = 0, cnt_spectial = 0, cnt_num = 0;
        char[] chs = password.toCharArray();
        Set<Character> set = new HashSet<>();
        for (char c : "!@#$%^&*()-+".toCharArray()) {
            set.add(c);
        }
        for (int i = 0; i < chs.length; i++) {
            if (i != 0 && chs[i] == chs[i - 1]) return false;
            if (Character.isDigit(chs[i])) cnt_num++;
            else if (Character.isLowerCase(chs[i])) cnt_small++;
            else if (Character.isUpperCase(chs[i])) cnt_big++;
            else if (set.contains(chs[i])) cnt_spectial++;
            else return false;
        }
        if (cnt_spectial > 0 && cnt_small > 0 && cnt_big > 0 && cnt_num > 0) return true;
        return false;
    }
}