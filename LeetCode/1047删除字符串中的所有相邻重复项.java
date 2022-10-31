class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> sta = new Stack<>();
        char[] chs = s.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            if (sta.isEmpty() || sta.peek() != chs[i]) {
                sta.push(chs[i]);
            } else {
                sta.pop();
            }
        }
        String str = "";
        while (!sta.isEmpty()) {
            str = sta.pop() + str;
        }
        return str;
    }
}

//使用stringbuffer在原地修改字符串
class Solution {
    public String removeDuplicates(String s) {
        StringBuffer sb = new StringBuffer();
        int top = -1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (top >= 0 && sb.charAt(top) == ch) {
                sb.deleteCharAt(top);
                top--;
            } else {
                sb.append(ch);
                top++;
            }
        }
        return sb.toString();
    }
}