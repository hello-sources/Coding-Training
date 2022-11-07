/**
 * 使用迭代法
 * 1、先把范围框定在[low, high]里面
 * 2、在[low,high]范围里，处理子孩子小于low的情况
 * 3、在[low, high]范围里，处理子孩子大于high的情况
 * 所谓的删除，无非是修改指针的指向，原有的父节点不在只想本节点
 */
class Solution {
    public TreeNode trimBST(TreeNode root, int low, int high) {
        if (root == null) return null;
        while (root != null && (root.val < low || root.val > high)) {
            if (root.val < low) root = root.right;
            else root = root.left;
        }
        TreeNode cur = root;
        while (cur != null) {
            while (cur.left != null && cur.left.val < low) {
                cur.left = cur.left.right;
            }
            cur = cur.left;
        }
        cur = root;
        while (cur != null) {
            while (cur.right != null && cur.right.val > high) {
                cur.right = cur.right.left;
            }
            cur = cur.right;
        }
        return root;
    }
}