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
    public int sumOfLeftLeaves(TreeNode root) {
        Stack<TreeNode> sta = new Stack<>();
        int ans = 0;
        if (root != null) sta.push(root);
        while (!sta.isEmpty()) {
            TreeNode node = sta.peek();
            sta.pop();
            if (node.left != null && node.left.left == null && node.left.right == null) {
                ans += node.left.val;
            }
            if (node.left != null) sta.push(node.left);
            if (node.right != null) sta.push(node.right);
        }
        return ans;
    }
}