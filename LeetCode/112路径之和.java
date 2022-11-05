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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        Stack<TreeNode> sta = new Stack<>();
        Stack<Integer> sum = new Stack<>();
        if (root != null) {
            sta.push(root);
            sum.push(root.val);
        }
        while (!sta.isEmpty()) {
            int size = sta.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = sta.pop();
                int tempSum = sum.pop();
                if (node.left == null && node.right == null && tempSum == targetSum) return true;
                if (node.left != null) {
                    sta.push(node.left);
                    sum.push(tempSum + node.left.val);
                }
                if (node.right != null) {
                    sta.push(node.right);
                    sum.push(tempSum + node.right.val);
                }
            }
        }
        return false;
    }
}