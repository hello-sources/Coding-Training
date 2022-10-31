class Solution {
    public boolean isValid(String s) {
        if (s.length() % 2 != 0) return false;
        char[] chs = s.toCharArray();
        Stack<Character> sta = new Stack();
        for (int i = 0; i < chs.length; i++) {
            if (chs[i] == '(') sta.push(')');
            else if (chs[i] == '[') sta.push(']');
            else if (chs[i] == '{') sta.push('}');
            else if (sta.isEmpty() || sta.peek() != chs[i]) return false;
            else sta.pop();
        }
        return sta.isEmpty();
    }
}