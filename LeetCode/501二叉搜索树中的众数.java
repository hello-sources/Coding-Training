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
    public void inOrder(TreeNode root, HashMap<Integer, Integer> hash) {
        if (root == null) return ;
        inOrder(root.left, hash);
        hash.put(root.val, hash.getOrDefault(root.val, 0) + 1);
        inOrder(root.right, hash);
        return ;
    }

    public int[] findMode(TreeNode root) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        if (root == null) return list.stream().mapToInt(Integer::intValue).toArray();
        inOrder(root, hash);
        List<Map.Entry<Integer, Integer>> mapList = hash.entrySet().stream()
            .sorted((c1, c2) -> c2.getValue().compareTo(c1.getValue()))
            .collect(Collectors.toList());
        list.add(mapList.get(0).getKey());
        for (int i = 1; i < mapList.size(); i++) {
            if (mapList.get(i).getValue() == mapList.get(i - 1).getValue()) {
                list.add(mapList.get(i).getKey());
            } else break;
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}

/**
 * 1、list转换为array需要用流处理
 * 2、对HashMap进行自定义排序获取众数
 */