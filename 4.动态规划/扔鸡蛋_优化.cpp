/*************************************************************************
    > File Name: OJ50扔鸡蛋_优化.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 12:01:23 AM CST
 ************************************************************************/


#include <iostream>
using namespace std;
#define MAX_N 32
#define MAX_M 65535 

long long dp[MAX_N + 5][MAX_M + 5];//状态互换 
//状态定义优化 
int main() {
	long long n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << m << endl;//如果是一个鸡蛋，那么直接就是对应楼层数 
		return 0;
	}  
	for (long long k = 1; k <= MAX_M; k++) dp[1][k] = k;//初始化状态转移数组 
	for (long long i = 2; i <= n; i++) {
		for (long long k = 1; k <= MAX_M; k++) {
			dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
			//dp[n][k]表示n个鸡蛋扔k次，最多能测多少层楼
			//抽象化状态转移函数f(x,k) = f(x-1,k-1)+f(x-1,k)+1，对应状态转移结果就是层数 
		}
	}
	long long p = 1;
	while (dp[n][p] < m) p++;
	cout << p << endl;
	return 0;
}
