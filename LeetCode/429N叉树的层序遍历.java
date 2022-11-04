/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ans = new ArrayList<>();
        Queue<Node> que = new LinkedList<>();
        if (root != null) que.add(root);
        while (!que.isEmpty()) {
            int size = que.size();
            List<Integer> temp = new ArrayList<>();
            while (size-- > 0) {
                Node node = que.poll();
                temp.add(node.val);
                for (int i = 0; i < node.children.size(); i++) {
                    que.offer(node.children.get(i));
                }
            }
            ans.add(temp);
        }
        return ans;
    }
}