/*************************************************************************
	> File Name: OJ481冰壶比赛.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 27 Jul 2020 11:13:48 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int r, ans[15][2];

void p(int x) {
	int ans1 = 0, ans2 = 0;
	for (int i=  0; i < x; i++) {
		cout << ans[i][0] << ":" << ans[i][1] << endl;
		ans1 += ans[i][0];
		ans2 += ans[i][1];
	}
	cout << ans1 << ":" << ans2 << endl;
}

int main() {
	cin >> r;
	for (int i = 0; i < 10; i++) {
		int num1[10], num2[10];
		for (int j = 0; j < 8; j++) {
			cin >> num1[j];
			if (num1[j] == -1) {
				p(i);
				return 0;
			}
		}
		for (int j = 0; j < 8; j++) {
			cin >> num2[j];
		}
		sort(num1, num1 + 8);
		sort(num2, num2 + 8);
		if (num1[0] < num2[0]) {
			for (int j = 0; j < 8; j++) {
				if (num1[j] > r || num1[j] >= num2[0]) break;
				ans[i][0]++;
			}
		} else {
			for (int j = 0; j < 8; j++) {
				if (num2[j] > r || num2[j] >= num1[0]) break;
				ans[i][1]++;
			}
		}
	}
	p(10);
	return 0;
} 
