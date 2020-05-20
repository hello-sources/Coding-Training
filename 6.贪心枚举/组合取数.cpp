/*************************************************************************
    > File Name: 组合取数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 07:04:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, r, num[35], cnt;

int judge(int n) {
	if (n <= 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		return 0;
	}
	return 1;
}

void calc(int s, int sum, int left) {
	if (left == 0) {
		cnt += judge(sum);
//		cout << sum << endl;
		return ;
	}
	for (int i = s; i <= n - left; i++) {
		sum += num[i];
		calc(i + 1, sum, left - 1);
		sum -= num[i];
	}
}

int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	calc(0, 0, r); 
	cout << cnt << endl;
	return 0;
}
