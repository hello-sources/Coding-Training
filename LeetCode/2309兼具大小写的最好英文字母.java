import java.util.HashSet;

/**
 * 瘸腿程序
 */
class Solution {
    public String greatestLetter(String s) {
        String res = "";
        char record = 'a';
        char[] chs = s.toCharArray();
        Set<Character> set = new HashSet<>();
        for (char ch : chs) set.add(ch);
        for (int i = 0; i < chs.length; i++) {
            char ch = 'a';
            if (Character.isLowerCase(chs[i]) && set.contains(chs[i] - 32)) ch = Character.toUpperCase(chs[i]);
            if (Character.isUpperCase(chs[i]) && set.contains(chs[i] + 32)) ch = chs[i];
            if (Character.valueOf(ch).compareTo(Character.valueOf(record)) > 0) record = ch;
        }
        return Character.toString(record);
    }
}

/**
 * 使用额外数组做法
 */
class Solution {
    public String greatestLetter(String s) {
        int[] lower = new int[26];
        int[] upper = new int[26];
        for (char ch : s.toCharArray()) {
            if (Character.isLowerCase(ch)) lower[ch - 'a']++;
            else upper[ch - 'A']++; 
        }
        for (int i = 25; i >= 0; i--) {
            if (lower[i] > 0 && upper[i] > 0) return Character.toString(i + 'A');
        }
        return "";
    }
}