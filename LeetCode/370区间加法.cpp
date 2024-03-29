/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getModifiedArray(int length, int** updates, int updatesSize, int* updatesColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * length);
    memset(res, 0, sizeof(int) * length);
    for (int i = 0; i < updatesSize; i++) {
        for (int j = updates[i][0]; j <= updates[i][1]; j++) {
            res[j] += updates[i][2];
        }
    }
    *returnSize = length;
    return res;
}

/*************差分数组*********/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (auto &x : updates) {
            ans[x[0]] += x[2];
            if (x[1] + 1 < length) ans[x[1] + 1] -= x[2];
        }
        for (auto i = 1; i < length; i++) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};