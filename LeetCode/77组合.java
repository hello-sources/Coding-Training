class Solution {
    List<List<Integer>> ans;
    List<Integer> path;
    public List<List<Integer>> combine(int n, int k) {
        ans = new ArrayList<>();
        path = new ArrayList<>();
        backtracking(1, n, k);
        return ans;
    }

    public void backtracking(int left, int n, int k) {
        if (path.size() == k) {
            ans.add(new ArrayList<>(path));
            return ;
        }
        for (int i = left; i <= n - (k - path.size() - 1); i++) {
            path.add(i);
            backtracking(i + 1, n, k);
            path.remove(path.size() - 1);
        }
        return ;
    }
}

/*
 * Java是值传递，List是引用传递，传来传去指向的都是同一空间
 * path.remove(path.size() - 1);在回溯过程中，path最后变空了，然后ans.add(path)时候就是空的
 * 一个合理的解释是list作为方法的参数，方法结束后栈会被回收，所有内容包括变量不再有效
 */