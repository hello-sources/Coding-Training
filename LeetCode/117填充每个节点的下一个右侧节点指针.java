/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Queue<Node> que = new LinkedList<>();
        if (root != null) que.add(root);
        while (!que.isEmpty()) {
            int size = que.size();
            Node node, pre = null;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    pre = que.poll();
                    node = pre;
                } else {
                    node = que.poll();
                    pre.next = node;
                    pre = pre.next;
                }
                if (node.left != null) que.add(node.left);
                if (node.right != null) que.add(node.right);
            }
        }
        return root;
    }
}