/*************************************************************************
	> File Name: OJ545导弹拦截.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 05 Aug 2020 01:56:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[30005][3]; 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i][0];
	}
	//最长不上升子序列 
	for (int i = 0; i <= n; i++) {
		int f = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (num[j][1] >= num[i][1] && num[i][0] <= num[j][0]) {
				num[i][1] = num[j][1] + 1;
				f = 1;
			}
		}
		if (f == 0) {
			num[i][1] = 1;
		}
	}
	//最长上升子序列 
	for (int i = 0; i <= n; i++) {
		int f = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (num[j][2] >= num[i][2] && num[i][0] > num[j][0]) {
				num[i][2] = num[j][2] + 1;
				f = 1;
			}
		}
		if (f == 0) {
			num[i][2] = 1;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < n; i++) {
		if (num[i][1] > num[ans1][1]) ans1 = i;
		if (num[i][2] > num[ans2][2]) ans2 = i;
	}
	cout << num[ans1][1] << " " << num[ans2][2] << endl;
	return 0;
}
