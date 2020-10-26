/*************************************************************************
	> File Name: OJ564起床困难症.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 27 Oct 2020 06:27:33 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
struct Data {
	string op;
	long long val;
} arr[MAX_N + 5];
long long n, m;

long long black_box(long long x) {
	for (long long i = 0; i < n; i++) {
		switch (arr[i].op[0]) {
			case 'A': x &= arr[i].val; break;
			case 'O': x |= arr[i].val; break;
			case 'X': x ^= arr[i].val; break;
		}
	}
	return x;
}

int main() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i].op >> arr[i].val;
	}
	long long x1 = 0, x2 = -1, ans = 0;
	x1 = black_box(x1);
	x2 = black_box(x2);
	for (long long i = 31; i >= 0; i--) {
		if (x1 & (1LL << i)) continue;
		if (x2 & (1LL << i) && (1LL << i) <= m) {
			ans |= (1LL << i);
			m -= (1LL << i);
		}  
	}
	cout << black_box(ans) << endl;
	return 0;
} 
