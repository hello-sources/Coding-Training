/*************************************************************************
	> File Name: OJ352数字组合.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 28 Sep 2020 09:24:38 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000
int f[MAX_N + 5]; 

int main() {
	int n, a, m;
	cin >> n >> m;
	f[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = m; j >= a; j--) {
			f[j] += f[j - a];
		}
	} 
	cout << f[m] << endl;
	return 0;
} 
