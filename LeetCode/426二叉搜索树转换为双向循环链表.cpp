/**
 * dfs(cur): 递归法中序遍历；
 * 终止条件： 当节点 cur 为空，代表越过叶节点，直接返回；   
 * 递归左子树，即 dfs(cur.left) ；
 * 构建链表：
    * 当 pre 为空时： 代表正在访问链表头节点，记为 head ；
    * 当 pre 不为空时： 修改双向节点引用，即 pre.right = cur ， cur.left = pre ；
    * 保存 cur ： 更新 pre = cur ，即节点 cur 是后继节点的 pre ；
 * 递归右子树，即 dfs(cur.right) ；
 * 
 * treeToDoublyList(root)：
 * 特例处理： 若节点 root 为空，则直接返回；
 * 初始化： 空节点 pre ；
 * 转化为双向链表： 调用 dfs(root) ；
 * 构建循环链表： 中序遍历完成后，head 指向头节点， pre 指向尾节点，因此修改 head 和 pre 的双向节点引用即可；
 * 返回值： 返回链表的头节点 head 即可；
 * **/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node *head, *pre;
    void dfs(Node *cur) {
        if (cur == nullptr) return ;
        dfs(cur->left);
        if (pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
        return ;
    }
};