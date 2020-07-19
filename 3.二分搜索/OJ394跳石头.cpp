/*************************************************************************
	> File Name: OJ394跳石头.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 19 Jul 2020 10:04:42 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int l1, n, m, num[50005];
	cin >> l1 >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	num[n + 1] = l1;//终点距离 
	int l = 0, r = l1;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		int cnt = 0, last = 0;//cnt表示移走石头数量，上一次位置 
		for (int i = 1; i <= n + 1; i++) {
			if (num[i] - last < mid) {
				cnt++;//表示最短距离小于mid石头得移走 
			} else {
				last = num[i];//否则last更新为num[i] 
			}
		}
		if (cnt <= m) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl; 
	return 0;
} 
