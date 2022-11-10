class Solution {
    List<List<Integer>> ans;
    LinkedList<Integer> path;
    public List<List<Integer>> combinationSum3(int k, int n) {
        ans = new ArrayList<>();
        path = new LinkedList<>();
        backtracking(1, 0, k, n);
        return ans;
    }

    public void backtracking(int left, int sum, int k, int n) {
        if (sum > n) return ;
        if (path.size() == k && sum == n) {
            ans.add(new ArrayList<>(path));
            return ;
        }
        for (int i = left; i <= 9 - (k - path.size() - 1); i++) {
            sum += i;
            path.add(i);
            backtracking(i + 1, sum, k, n);
            path.removeLast();
            sum -= i;
        }
        return ;
    }
}