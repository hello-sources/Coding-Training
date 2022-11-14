class Solution {
    public String customSortString(String order, String s) {
        StringBuffer ans = new StringBuffer();
        char[] str = s.toCharArray();
        for (int i = 0; i < order.length(); i++) {
            for (int j = 0; j < str.length; j++) {
                if (order.charAt(i) == str[j]) {
                    ans.append(str[j]);
                    str[j] = '.';
                }
            }
        }
        for (int i = 0; i < str.length; i++) {
            if (str[i] == '.') continue;
            ans.append(str[i]);
        }
        return ans.toString();
    }
}