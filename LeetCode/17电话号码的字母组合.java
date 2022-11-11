class Solution {
    List<String> ans;
    public List<String> letterCombinations(String digits) {
        ans = new ArrayList<>();
        if (digits == null || digits.length() == 0) return ans;
        String[] nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(digits, nums, 0);
        return ans;
    }

    StringBuilder sb = new StringBuilder();
    public void backtracking(String digits, String[] nums, int cnt) {
        if (cnt == digits.length()) {
            ans.add(sb.toString());
            return ;
        }
        String str = nums[digits.charAt(cnt) - '0'];
        for (int i = 0; i < str.length(); i++) {
            sb.append(str.charAt(i));
            backtracking(digits, nums, cnt + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}