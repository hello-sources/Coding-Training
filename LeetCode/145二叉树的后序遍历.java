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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        Stack<TreeNode> sta = new Stack<>();
        TreeNode pre = null;
        while (root != null || !sta.isEmpty()) {
            while (root != null) {
                sta.push(root);
                root = root.left;
            }
            root = sta.pop();
            if (root.right == null || root.right == pre) {
                ans.add(root.val);
                pre = root;
                root = null;
            } else {
                sta.push(root);
                root = root.right;
            }
        }
        return ans;
    }
}

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> sta = new Stack<>();
        if (root == null) return ans;
        sta.push(root);
        while (!sta.isEmpty()) {
            TreeNode cur = sta.pop();
            ans.add(cur.val);
            if (cur.left != null) sta.push(cur.left);
            if (cur.right != null) sta.push(cur.right);
        }
        Collections.reverse(ans);
        return ans;
    }
}