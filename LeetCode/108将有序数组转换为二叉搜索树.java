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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) return null;
        Queue<TreeNode> nodeQue = new LinkedList<>();
        Queue<Integer> lque = new LinkedList<>();
        Queue<Integer> rque = new LinkedList<>();
        TreeNode root = new TreeNode(0);
        nodeQue.add(root);
        lque.add(0);
        rque.add(nums.length - 1);
        while (!nodeQue.isEmpty()) {
            TreeNode node = nodeQue.poll();
            int left = lque.poll();
            int right = rque.poll();
            int mid = left + (right - left) / 2;
            node.val = nums[mid];
            if (left <= mid - 1) {
                node.left = new TreeNode(0);
                nodeQue.add(node.left);
                lque.add(left);
                rque.add(mid - 1);
            }
            if (right >= mid + 1) {
                node.right = new TreeNode(0);
                nodeQue.add(node.right);
                lque.add(mid + 1);
                rque.add(right);
            }
        }
        return root;
    }
}