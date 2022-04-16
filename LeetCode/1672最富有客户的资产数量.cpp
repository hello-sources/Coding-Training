int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int max = 0;
    for (int i = 0; i < accountsSize; i++) {
        int temp = 0;
        for (int j = 0; j < accountsColSize[0]; j++) {
            temp += accounts[i][j];
        }
        max = fmax(max, temp);
    }
    return max;
}

/*************************************************/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        for (auto &x : accounts) {
            ans = max(ans, accumulate(x.begin(), x.end(), 0));
        }
        return ans;
    }
};