/*************************************************************************
	> File Name: OJ234占卜.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 09 Jul 2020 08:22:49 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int num[4], flag;
}; 

node pai[13];

int main() {
	for (int i = 0; i < 13; i++) {
		for (int j = 3; j >= 0; j--) {
			char t;
			cin >> t;
			if (t == 'A') {
				pai[i].num[j] = 1;
			} else if (t == 'J') {
				pai[i].num[j] = 11;
			} else if (t == 'Q') {
				pai[i].num[j] = 12;
			} else if (t == 'K') {
				pai[i].num[j] = 13;
			} else if (t == '0') {
				pai[i].num[j] = 10;
			} else {
				pai[i].num[j] = t - '0';
			}
		}
	}
	swap(pai[12].num[0], pai[12].num[3]);
	swap(pai[12].num[1], pai[12].num[2]);
	int left = 0, ans = 0;
	while (left != 4 && ans != 12) {
		int now = pai[12].num[left];
		while (now != 13) {
			pai[now - 1].flag++;
			if (pai[now - 1].flag == 4) ans++;
			now = pai[now - 1].num[pai[now - 1].flag - 1];
		}
		left++;
	}
	cout << ans << endl;
	return 0;
}
