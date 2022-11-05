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
    public TreeNode calc(int[] nums, int left, int right) {
        if (left >= right) return null;
        int maxInd = left;
        for (int i = maxInd + 1; i < right; i++) {
            if (nums[i] > nums[maxInd]) maxInd = i;
        }
        TreeNode root = new TreeNode(nums[maxInd]);
        root.left = calc(nums, left, maxInd);
        root.right = calc(nums, maxInd + 1, right);
        return root;
    }

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return calc(nums, 0, nums.length);
    }
}