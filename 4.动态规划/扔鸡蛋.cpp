/*************************************************************************
    > File Name: OJ50扔鸡蛋.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Tue 12 May 2020 11:42:29 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 32
#define MAX_M 10000 

int dp[MAX_N + 5][MAX_M + 5];//表示n鸡蛋，从m层楼向下扔 
int f[MAX_N + 5][MAX_M + 5];//表示从那一层楼向下扔鸡蛋 

int main() {
	int n, m;
	cin >> n >> m;//鸡蛋与楼层数 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				dp[i][j] = j;//初始化状态转移函数的时候，由于鸡蛋数为1，导致最坏的结果就是楼层数 
				f[i][j] = 1;//表示每一次扔鸡蛋的楼层， 
				continue;
			}
			dp[i][j] = j;//按照状态转移函数第一次定位在当前楼层位置 
			for (int k = 1; k <= j; k++) {
				//根据状态转移公式dp[n] [m] = min(dp[n] [m], max(dp[n - 1] [k - 1], dp[ n] [m - k])) + 1 
				int val = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
				if (val < dp[i][j]) {
					f[i][j] = k;//f数组记录的是对应扔鸡蛋楼层信息 
					dp[i][j] = val;
				} 
			}
		}
	} 	
	cout << dp[n][m] << endl;//输出对应次数 
	int sum = 0;
	while (sum < m) {
		cout << sum + f[n][m - sum] << " ";//输出每一次扔鸡蛋的楼层 
		sum += f[n][m - sum];
		if (f[n][m - sum] == 0) {
			sum += 1;
			break;
		}
	}
	cout << endl;
	return 0;
}
