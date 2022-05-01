/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if (tree == nullptr) return ans;
        queue<TreeNode*> que;
        que.push(tree);
        while (!que.empty()) {
            int size = que.size();
            ListNode *cur = new ListNode(0);
            ListNode *net = cur;
            while (size--) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                ListNode *newnode = new ListNode(node->val);
                net->next = newnode;
                net = net->next;
            }
            ans.push_back(cur->next);
        }
        return ans;
    }

private:
    vector<ListNode*> ans;
};