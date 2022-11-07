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
    private void calc(TreeNode root, int sum) {
       Stack<TreeNode> sta = new Stack<>();
       TreeNode cur = root;
       while (cur != null || !sta.isEmpty()) {
           if (cur != null) {
               sta.add(cur);
               cur = cur.right;
           } else {
               cur = sta.pop();
               sum += cur.val;
               cur.val = sum;
               cur = cur.left;
           }
       }
       return ;
    }

    public TreeNode convertBST(TreeNode root) {
        int sum = 0;
        calc(root, sum);
        return root;
    }
}