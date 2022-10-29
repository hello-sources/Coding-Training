class Solution {
    public String reverseWords(String s) {
        StringBuffer sb = removeSpace(s);
        reverseString(sb, 0, sb.length() - 1);
        reverseWords(sb);
        return sb.toString();
    }

    public StringBuffer removeSpace(String s) {
        int left = 0, right = s.length() - 1;
        while (s.charAt(left) == ' ') left++;
        while (s.charAt(right) == ' ') right--;
        StringBuffer sb = new StringBuffer();
        while (left <= right) {
            if (s.charAt(left) != ' ' || sb.charAt(sb.length() - 1) != ' ') {
                sb.append(s.charAt(left));
            }
            left++;
        }
        return sb;
    }

    public void reverseString(StringBuffer sb, int left, int right) {
        while (left <= right) {
            char ch = sb.charAt(left);
            sb.setCharAt(left, sb.charAt(right));
            sb.setCharAt(right, ch);
            left++;
            right--;
        }
        return ;
    }

    public void reverseWords(StringBuffer sb) {
        int left = 0, right = 1;
        int n = sb.length();
        while (left < n) {
            while (right < n && sb.charAt(right) != ' ') right++;
            reverseString(sb, left, right - 1);
            left = right + 1;
            right = left + 1;
        }
        return ;
    }
}