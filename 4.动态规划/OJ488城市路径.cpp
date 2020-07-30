/*************************************************************************
	> File Name: OJ488城市路径.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 30 Jul 2020 12:36:12 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int n, num[100005][2], mmin, all;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i][0] >> num[i][1];
		if (i > 1) {
			all += abs(num[i][0] - num[i - 1][0]) +
				   abs(num[i][1] - num[i - 1][1]);
		}
	} 
	mmin = all;
	for (int i = 2; i < n; i++) {
		int t = all;
		t -= abs(num[i][0] - num[i - 1][0]) +
			 abs(num[i][1] - num[i - 1][1]) +
			 abs(num[i][0] - num[i + 1][0]) +
			 abs(num[i][1] - num[i + 1][1]);
		t += abs(num[i + 1][0] - num[i - 1][0]) +
			 abs(num[i + 1][1] - num[i - 1][1]);
		if (t < mmin) {
			mmin = t;
		}
	} 
	cout << mmin << endl;
	return 0;
} 
