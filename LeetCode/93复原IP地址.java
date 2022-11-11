class Solution {
    List<String> ans = new ArrayList<>();
    public List<String> restoreIpAddresses(String s) {
        if (s.length() > 12) return ans;
        backtracking(s, 0, 0);
        return ans;
    }

    public void backtracking(String s, int ind, int cnt) {
        if (cnt == 3) {
            if (isValid(s, ind, s.length() - 1)) {
                ans.add(s);
            }
            return ;
        }
        for (int i = ind; i < s.length(); i++) {
            if (isValid(s, ind, i)) {
                s = s.substring(0, i + 1) + "." + s.substring(i + 1);
                cnt++;
                backtracking(s, i + 2, cnt);
                cnt--;
                s = s.substring(0, i + 1) + s.substring(i + 2);
            } else break;
        }
    }

    public boolean isValid(String s, int left, int right) {
        if (left > right) return false;
        if (s.charAt(left) == '0' && left != right) return false;
        int num = 0;
        for (int i = left; i <= right; i++) {
            if (s.charAt(i) > '9' || s.charAt(i) < '0') return false;
            num = num * 10 + s.charAt(i) - '0';
            if (num > 255) return false;
        }
        return true;
    }
}