class Solution {
    public char repeatedCharacter(String s) {
        int[] nums = new int[26];
        for (int i = 0; i < 26; i++) nums[i] = -1;
        for (char ch : s.toCharArray()) {
            nums[ch - 'a']++;
            if (nums[ch - 'a'] == 1) return ch;
        }
        return 'a';
    }
}