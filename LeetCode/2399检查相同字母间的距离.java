class Solution {
    public boolean checkDistances(String s, int[] distance) {
        int[] cnt = new int[26];
        Map<Character, Integer> map = new TreeMap<>();
        for (int i = s.length() - 1; i >= 0; i--) {
            Character ch = s.charAt(i);
            if (cnt[ch - 'a']++ > 2) return false;
            if (!map.containsKey(ch)) {
                map.put(ch, i);
            } else map.put(ch, map.get(ch) - i - 1);
        }
        for (Character ch : map.keySet()) {
            if (distance[ch - 'a'] != map.get(ch)) return false;
        }
        return true; 
    }
}