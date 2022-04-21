/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node *> u_set;
        for (auto &x : tree) {
            for (auto &y : x->children) {   
                u_set.insert(y);
            }
        }
        for (auto &x : tree) {
            if (u_set.find(x) == u_set.end()) return x;
        }
        return nullptr;
    }
};