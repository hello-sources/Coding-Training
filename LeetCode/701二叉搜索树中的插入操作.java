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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            TreeNode node = new TreeNode(val);
            return node;
        }
        TreeNode pre = root, cur = root;
        while (cur != null) {
            pre = cur;
            if (cur.val > val) cur = cur.left;
            else cur = cur.right;
        }
        TreeNode node = new TreeNode(val);
        if (val < pre.val) pre.left = node;
        else pre.right = node;
        return root;
    }
}

/**
 * 迭代法
 * 对于null的节点直接生成一个node，返回即可
 * 迭代法遍历时候需要记录当前节点的父节点，找到要插入的节点后
 * 判断是插入左侧还是插入right
 */