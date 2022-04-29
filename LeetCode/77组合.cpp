/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **res;
int resSize;
int *temp;
int tempSize;

void dfs(int cur, int n, int k) {
    if (tempSize + (n - cur + 1) < k) return ;
    if (tempSize == k) {
        int *tmp = (int *)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            tmp[i] = temp[i];
        }
        res[resSize++] = tmp;
        return ;
        return ;
    }
    temp[tempSize++] = cur;
    dfs(cur + 1, n, k);
    tempSize--;
    dfs(cur + 1, n, k);
    return ;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    res = (int **)malloc(sizeof(int *) * 10001);
    temp = (int *)malloc(sizeof(int) * (k + 5));
    tempSize = resSize = 0;
    dfs(1, n, k);
    *returnSize = resSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * resSize);
    for (int i = 0; i < resSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return res;
}

/********************C++******************/
class Solution {
public:
    void backtracking(int n, int k, int ind) {
        if (temp.size() == k) {
            ans.emplace_back(temp);
            return ;
        }
        for (int i = ind; i <= n; i++) {
            temp.emplace_back(i);
            backtracking(n, k, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }

private :
    vector<vector<int>> ans;
    vector<int> temp;
};