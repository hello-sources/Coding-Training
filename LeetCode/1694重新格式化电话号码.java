class Solution {
    public String reformatNumber(String number) {
        char[] ans = new char[number.length() + 100];
        int size = 0;
        if (number.length() < 3) return number;
        for (char ch : number.toCharArray()) {
            if (ch == ' ' || ch == '-') continue;
            if (size % 4 == 3) ans[size++] = '-';
            ans[size++] = ch;
        }
        if (size % 4 == 1) {
            char ch = ans[size - 3];
            ans[size - 3] = '-';
            ans[size - 2] = ch;
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < size; i++) {
            sb.append(ans[i]);
        }
        return sb.toString();
    }
}