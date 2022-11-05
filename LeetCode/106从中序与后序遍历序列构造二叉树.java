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
    public TreeNode build(int[] inorder, int leftInorder, int rightInorder, int[] postorder, int leftPostOrder, int rightPostOrder) {
        if (leftPostOrder == rightPostOrder) return null;
        int rootVal = postorder[rightPostOrder - 1];
        TreeNode root = new TreeNode(rootVal);
        if (rightPostOrder - leftPostOrder == 1) return root;
        int ind;
        for (ind = leftInorder; ind < rightInorder; ind++) {
            if (inorder[ind] == root.val) break;
        }
        int leftInorderLeft = leftInorder;
        int leftInorderRight = ind;
        int rightInorderLeft = ind + 1;
        int rightInorderRight = rightInorder;
        int leftPostOrderLeft = leftPostOrder;
        int leftPostOrderRight = leftPostOrder + ind - leftInorder;
        int rightPostOrderLeft = leftPostOrder + ind - leftInorder;
        int rightPostOrderRight = rightPostOrder - 1;
        root.left = build(inorder, leftInorderLeft, leftInorderRight, postorder, leftPostOrderLeft, leftPostOrderRight);
        root.right = build(inorder, rightInorderLeft, rightInorderRight, postorder, rightPostOrderLeft, rightPostOrderRight);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0 || postorder.length == 0) return null;
        return build(inorder, 0, inorder.length, postorder, 0, postorder.length);
    }
}