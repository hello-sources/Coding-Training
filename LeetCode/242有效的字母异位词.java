class Solution {
    public boolean isAnagram(String s, String t) {
        int[] str = new int[26];
        for (int i = 0; i < s.length(); i++) {
            str[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            str[t.charAt(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (str[i] != 0) {
                return false;
            }
        }
        return true;
    }
}

//使用库函数
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) - 1);
            if (map.get(ch) < 0) {
                return false;
            }
        }
        return true;
    }
}