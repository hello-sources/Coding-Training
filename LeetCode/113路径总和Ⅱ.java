/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<List<Integer>> ans;
    List<Integer> path;

    public void calc(TreeNode root, int sum) {
        if (root == null) return ;
        path.add(root.val);
        sum -= root.val;
        if (root.left == null && root.right == null && sum == 0) {
            ans.add(new ArrayList<>(path));
        }
        if (root.left == null && root.right == null) return ;
        if (root.left != null) {
            calc(root.left, sum);
            path.remove(path.size() - 1);
        }
        if (root.right != null) {
            calc(root.right, sum);
            path.remove(path.size() - 1);
        }
        return ;
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        ans = new ArrayList<>();
        path = new ArrayList<>();
        if (root == null) return ans;
        calc(root, targetSum);
        return ans;
    }
}