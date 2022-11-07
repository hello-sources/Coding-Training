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
    public int minDiffInBST(TreeNode root) {
        Stack<TreeNode> sta = new Stack<>();
        TreeNode pre = null;
        TreeNode cur = root;
        int ans = 100005;
        while (cur != null || !sta.isEmpty()) {
            if (cur != null) {
                sta.push(cur);
                cur = cur.left;
            } else {
                cur = sta.pop();
                if (pre != null) {
                    ans = Math.min(ans, Math.abs(pre.val - cur.val));
                }
                pre = cur;
                cur = cur.right;
            }
        }
        return ans;
    }
}