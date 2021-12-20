bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right){
    int flag[52] = {0};
    for (int i = 0; i < rangesSize; i++) {
        for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
            flag[j] = 1;
        }
    }
    for (int i = left; i <= right; i++) {
        if (flag[i] == 0) return false;
    }
    return true;
}


/******************差分数组********************/
/**
 * 可以用差分数组diff 维护相邻两个整数的被覆盖区间数量变化量，其中diff[i] 对应覆盖整数 i 的区间数量相对于覆盖i−1 的区间数量变化量。
 * 这样，当遍历到闭区间[l,r] 时，l 相对于 l - 1 被覆盖区间数量多 1，r + 1相对于 r 被覆盖区间数量少 1。
 * 对应到差分数组上，我们需要将 diff[l] 加上 1，并将 diff[r+1] 减去 1。
 * 在维护完差分数组diff 后，我们遍历diff 求前缀和得出覆盖每个整数的区间数量。下标 i 对应的被覆盖区间数量即为初始数量 0 加上 [1,i] 闭区间的变化量之和。
 * 在计算被覆盖区间数量的同时，我们可以一并判断[left,right] 闭区间内的所有整数是否都被覆盖
 * **/
bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right){
    int flag[52] = {0};
    for (int i = 0; i < rangesSize; i++) {
        ++flag[ranges[i][0]];
        --flag[ranges[i][1] + 1];
    }
    int ans = 0;
    for (int i = 0; i < 52; i++) {
        ans += flag[i];
        if (i >= left && i <= right && ans <= 0) return false;
    }
    return true;
}