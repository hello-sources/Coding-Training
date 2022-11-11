class Solution {
    List<List<Integer>> ans;
    LinkedList<Integer> nums;
    boolean[] used;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        ans = new ArrayList<>();
        nums = new LinkedList<>();
        used = new boolean[candidates.length];
        Arrays.fill(used, false);
        Arrays.sort(candidates);
        backtracking(0, 0, candidates, target);
        return ans;
    }

    public void backtracking(int ind, int sum, int[] candidates, int target) {
        if (sum == target) {
            ans.add(new ArrayList<>(nums));
            return ;
        }
        for (int i = ind; i < candidates.length && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            sum += candidates[i];
            nums.add(candidates[i]);
            backtracking(i + 1, sum, candidates, target);
            nums.removeLast();
            sum -= candidates[i];
            used[i] = false;
        }
        return ;
    }
}

/**
 * Arrays.fill(arr, val)  给arr数组的每个元素赋值为val
 * 由于每个数字在每个组合中只能使用一次，所以需要一个数组来判断是否使用过.
 */