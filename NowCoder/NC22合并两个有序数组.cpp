/**
 * 
 * @param A int整型一维数组 
 * @param ALen int A数组长度
 * @param B int整型一维数组 
 * @param BLen int B数组长度
 * @return void
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    // write code here
    ALen = m - 1, BLen = n - 1;
    int index = m + n - 1;
    while (ALen >= 0 && BLen >= 0) {
        A[index--] = A[ALen] > B[BLen] ? A[ALen--] : B[BLen--];
    }
    while (BLen >= 0) {
        A[index--] = B[BLen--];
    }
}