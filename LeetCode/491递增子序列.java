class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();

    public List<List<Integer>> findSubsequences(int[] nums) {
        backtracking(nums, 0);
        return ans;
    }

    public void backtracking(int[] nums, int ind) {
        if (path.size() > 1) ans.add(new ArrayList<>(path));
        HashMap<Integer, Integer> hash = new HashMap<>();
        for (int i = ind; i < nums.length; i++) {
            if (!path.isEmpty() && nums[i] < path.getLast()) continue;
            if (hash.getOrDefault(nums[i], 0) >= 1) continue;
            hash.put(nums[i], hash.getOrDefault(nums[i], 0) + 1);
            path.add(nums[i]);
            backtracking(nums, i + 1);
            path.removeLast();
        }
    }
}