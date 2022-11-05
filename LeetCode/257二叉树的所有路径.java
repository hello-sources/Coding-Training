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
    public void getPath(TreeNode root, String path, List<String> ans) {
        path += root.val;
        if (root.left == null && root.right == null) {
            ans.add(path);
            return ;
        }
        path += "->";
        if (root.left != null) getPath(root.left, path, ans);
        if (root.right != null) getPath(root.right, path, ans);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        String path = new String();
        if (root == null) return ans;
        getPath(root, path, ans);
        return ans;
    }
}