/**
 * 旋转数组
 * @param n int整型 数组长度
 * @param m int整型 右移距离
 * @param a int整型一维数组 给定数组
 * @param aLen int a数组长度
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
//使用额外数组空间
int* solve(int n, int m, int* a, int aLen, int* returnSize ) {
    // write code here
    *returnSize = 0;
    int *ans = (int *)malloc(sizeof(int) * n);
    for (int i = n - m % n; i < n; i++) {
        ans[(*returnSize)++] = a[i];
    }
    for (int i = 0; i < n - m % n; i++) {
        ans[(*returnSize)++] = a[i];
    }   
    return ans;
}

//不使用额外数组空间，连续反转数组三次，
//第一次反转整个数组，第二次反转0-m % n位置上的数字，
//第三次反转m % n + 1-n上面的数字