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
    public TreeNode build(int[] preorder, int preorderLeft, int preorderRight, int[] inorder, int inorderLeft, int inorderRight) {
        if (preorderRight <= preorderLeft || inorderRight <= inorderLeft) return null;
        int rootVal = preorder[preorderLeft];
        TreeNode root = new TreeNode(rootVal);
        int ind;
        for (ind = inorderLeft; ind < inorderRight; ind++) {
            if (inorder[ind] == rootVal) break;
        }
        int leftpreorderLeft = preorderLeft + 1;
        int leftpreorderRight = preorderLeft + ind - inorderLeft + 1;
        int rightpreorderLeft = preorderLeft + ind - inorderLeft + 1;
        int rightpreorderRight = preorderRight;
        int leftinorderLeft = inorderLeft;
        int leftinorderRight = inorderLeft + ind - inorderLeft;
        int rightinorderLeft = inorderLeft + ind - inorderLeft + 1;
        int rightinorderRight = inorderRight;
        root.left = build(preorder, leftpreorderLeft, leftpreorderRight, inorder, leftinorderLeft, leftinorderRight);
        root.right = build(preorder, rightpreorderLeft, rightpreorderRight, inorder, rightinorderLeft, rightinorderRight);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0 || inorder.length == 0) return null;
        return build(preorder, 0, preorder.length, inorder, 0, inorder.length);
    }
}