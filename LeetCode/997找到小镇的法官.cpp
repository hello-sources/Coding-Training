/**
 * 题中给出的是一个有向图，而法官的入度则为n - 1,只要对应一个边，出度减一，入度加一，最后遍历数组的值是否等于n - 1即可
 * **/


int findJudge(int n, int** trust, int trustSize, int* trustColSize){
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < trustSize; i++) {
        cnt[trust[i][0]]--;
        cnt[trust[i][1]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == n - 1) return i;
    }
    return -1;
}