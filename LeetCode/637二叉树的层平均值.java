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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> list = new ArrayList<>();
        Queue<TreeNode> que = new LinkedList<>();
        if (root != null) que.add(root);
        while (!que.isEmpty()) {
            int size = que.size();
            Double sum = 0.0;
            int cnt = size;
            while (size-- > 0) {
                TreeNode node = que.poll();
                sum += node.val;
                if (node.left != null) que.add(node.left);
                if (node.right != null) que.add(node.right);
            }
            list.add(sum / cnt);
        }
        return list;
    }
}