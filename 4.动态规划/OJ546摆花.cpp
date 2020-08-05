/*************************************************************************
	> File Name: OJ546摆花.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 05 Aug 2020 02:13:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//ans表示用第一维度的花摆放第二维的方案 
int n, m, num[105], ans[105][105]; 

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}	
	for (int i = 0; i <= num[0]; i++) {
		ans[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= num[i]; k++) {
				//用前i种花摆j盆的方案总数，不选这一种，从i - 1种摆放j - k盆 
				ans[i][j] += ans[i - 1][j - k];
				ans[i][j] %= 1000007;
				if (j - k == 0) break;
			}
		}
	}
	cout << ans[n - 1][m] << endl; 
	return 0;
} 
