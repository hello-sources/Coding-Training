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
    public boolean isSymmetric(TreeNode root) {
        Stack<TreeNode> sta = new Stack<>();
        if (root == null) return true;
        sta.add(root.left);
        sta.add(root.right);
        while (!sta.isEmpty()) {
            TreeNode leftNode = sta.peek();
            sta.pop();
            TreeNode rightNode = sta.peek();
            sta.pop();
            if (leftNode == null && rightNode == null) continue;
            if (leftNode == null || rightNode == null || leftNode.val != rightNode.val) return false;
            sta.add(leftNode.left);
            sta.add(rightNode.right);
            sta.add(leftNode.right);
            sta.add(rightNode.left);
        }
        return true;
    }
}