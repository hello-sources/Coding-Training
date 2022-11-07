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
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null) return root2;
        if (root2 == null) return root1;
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root1);
        que.add(root2);
        while (!que.isEmpty()) {
            TreeNode node1 = que.poll();
            TreeNode node2 = que.poll();
            node1.val += node2.val;
            if (node1.left != null && node2.left != null) {
                que.add(node1.left);
                que.add(node2.left);
            }
            if (node1.right != null && node2.right != null) {
                que.add(node1.right);
                que.add(node2.right);
            }
            if (node1.left == null && node2.left != null) {
                node1.left = node2.left;
            }
            if (node1.right == null && node2.right != null) {
                node1.right = node2.right;
            }
        }
        return root1;
    }
}