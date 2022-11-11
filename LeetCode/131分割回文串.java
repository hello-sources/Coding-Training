class Solution {
    List<List<String>> ans; 
    LinkedList<String> path;
    public List<List<String>> partition(String s) {
        ans = new ArrayList<>();
        path = new LinkedList<>();
        backtracking(0, s);
        return ans;
    }

    public void backtracking(int ind, String s) {
        if (ind >= s.length()) {
            ans.add(new ArrayList<>(path));
            return ;
        }
        for (int i = ind; i < s.length(); i++) {
            if (isValid(s, ind, i)) {
                String str = s.substring(ind, i + 1);
                path.add(str);
            } else continue;
            backtracking(i + 1, s);
            path.removeLast();
        }
        return ;
    }

    public boolean isValid(String s, int left, int right) {
        for (int i = left, j = right; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
    }
}