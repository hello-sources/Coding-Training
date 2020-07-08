/*************************************************************************
	> File Name: OJ231奇怪的汉诺塔.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 08 Jul 2020 10:11:41 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

//对于三根棍的情况f[n] = 2 * f[n - 1] + 1; 
//对于四根棍的情况 X[n] = 2 * X[i] + f[n - i]
//把四根棍的汉诺塔问题转换为三根棍的汉诺塔问题

int main() {
	int f[15] = {0, 1}, ans[15];
	for (int i = 2; i <= 12; i++) {
		f[i] = 2 * f[i - 1] + 1;
	}
	for (int i = 0; i <= 12; i++) {
		ans[i] = 1000000000;
	}
	ans[0] = 0;
	ans[1] = 1;
	for (int i = 2; i <= 12; i++) {
		for (int j = 1; j < i; j++) {
			ans[i] = min(ans[i], ans[j] * 2 + f[i - j]);
		}
	} 
	int n;
	cin >> n;
	cout << ans[n] << endl;
	
	return 0;
}
