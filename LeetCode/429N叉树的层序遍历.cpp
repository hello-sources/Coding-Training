/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NODE_SIZE 10000
#define MAX_LEVE_SIZE 1000

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int **res = (int **)malloc(sizeof(int *) * MAX_LEVE_SIZE);
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * MAX_LEVE_SIZE);
    if (root == NULL) {
        *returnSize = 0;
        return res;
    }
    struct Node **que = (struct Node **)malloc(sizeof(struct Node *) * MAX_NODE_SIZE);
    int head = 0, tail = 0, level = 0;
    que[tail++] = root;
    while (head != tail) {
        int cnt = tail - head;
        res[level] = (int *)malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; i++) {
            struct Node *cur = que[head++];
            res[level][i] = cur->val;
            for (int j = 0; j < cur->numChildren; j++) {
                que[tail++] = cur->children[j];
            }
        }
        (*returnColumnSizes)[level++] = cnt;
    }
    *returnSize = level;
    free(que);
    return res;
}


//C++做法
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            while (size--) {
                Node* node = que.front();
                que.pop();
                temp.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++) {
                    que.push(node->children[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};