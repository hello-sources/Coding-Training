/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node *, NodeCopy *> u_map;
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return dfs(root);
    }

    NodeCopy* dfs(Node *root) {
        if (root == nullptr) return nullptr;
        if (u_map.find(root) != u_map.end()) return u_map[root];
        NodeCopy *cur = new NodeCopy(root->val);
        u_map[root] = cur;
        cur->left = dfs(root->left);
        cur->right = dfs(root->right);
        cur->random = dfs(root->random);
        return cur;
    }
};