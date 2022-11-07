/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *ans;
int ansSize, base, cnt, max_cnt;

void update(int x) {
    if (x == base) cnt++;
    else {
        base = x;
        cnt = 1;
    }
    if (cnt == max_cnt) {
        ans[ansSize++] = base;
    }
    if (max_cnt < cnt) {
        max_cnt = cnt;
        ansSize = 0;
        ans[ansSize++] = base;
    }
}

void order(struct TreeNode *root) {
    if (root == NULL) return ;
    order(root->left);
    update(root->val);
    order(root->right);
    return ;
}

int* findMode(struct TreeNode* root, int* returnSize){
    base = cnt = max_cnt = ansSize = 0;
    ans = (int *)malloc(sizeof(int) * 4001);
    order(root);
    *returnSize = ansSize;
    return ans;
}


/**
 * C++
 */
class Solution {
public:
    void preOrder(TreeNode* root, map<int, int> &map) {
        if (root == nullptr) return ;
        map[root->val]++;
        preOrder(root->left, map);
        preOrder(root->right, map);
        return ;
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> map;
        vector<int> ans;
        if (root == nullptr) return ans;
        preOrder(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        ans.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) ans.push_back(vec[i].first);
            else break;
        }
        return ans;
    }
};