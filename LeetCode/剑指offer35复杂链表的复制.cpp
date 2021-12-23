/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    unordered_map<Node *, Node*> temp;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (!temp.count(head)) {
            Node *new_node = new Node(head->val);
            temp[head] = new_node;
            new_node->next = copyRandomList(head->next);
            new_node->random = copyRandomList(head->random);
        }
        return temp[head];
    }
};