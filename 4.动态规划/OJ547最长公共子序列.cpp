/*************************************************************************
	> File Name: OJ547最长公共子序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 06 Aug 2020 05:54:22 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

//递推表达式
//a[i] == b[j]   则 f[i][j] = f[i - 1][j - 1] + 1
//a[i] != b[j]   则 f[i][j] = f[i - 1][j]或者f[i][j - 1] 

int ans[5005][5005];
string a, b;

int main() {
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j]) {
				ans[i][j] = ans[i - 1][j - 1] + 1;
			} else {
				ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
			}
		}
	} 
	cout << ans[a.size() - 1][b.size() - 1] << endl;
	return 0;
} 
