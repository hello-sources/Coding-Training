class Solution {
    List<List<Integer>> ans;
    LinkedList<Integer> nums;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        ans = new ArrayList<>();
        nums = new LinkedList<>();
        backtracking(0, 0, candidates, target);
        return ans;
    }

    public void backtracking(int ind, int sum, int[] candidates, int target) {
        if (sum > target) return ;
        if (sum == target) {
            ans.add(new ArrayList<>(nums));
            return ;
        }
        for (int i = ind; i <= candidates.length - 1; i++) {
            sum += candidates[i];
            nums.add(candidates[i]);
            backtracking(i, sum, candidates, target);
            nums.removeLast();
            sum -= candidates[i];
        }
        return ;
    }
}