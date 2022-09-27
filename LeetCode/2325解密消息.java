/**
 * 使用StringBuffer尝试写入字符数据
 */
class Solution {
    public String decodeMessage(String key, String message) {
        Map<Character, Character> map = new HashMap<Character, Character>();
        for (int i = 0; i < key.length() && map.size() < 26; i++) {
            char ch = key.charAt(i);
            if (map.containsKey(ch) || ch == ' ') continue;
            map.put(ch, (char)('a' + map.size()));
        }
        StringBuffer res = new StringBuffer();
        for (char ch : message.toCharArray()) {
            if (ch == ' ') {
                res.append(' '); 
                continue;
            }
            res.append(map.get(ch));
        }
        return res.toString();
    }
}