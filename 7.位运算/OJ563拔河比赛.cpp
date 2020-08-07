/*************************************************************************
	> File Name: OJ563拔河比赛.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 07 Aug 2020 05:28:53 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
using namespace std;
#define MAX_N 500
#define MAX_M 500000
int f[MAX_M + 5]; 
int val[MAX_N + 5];

int main() {
	f[0] = 1;
	int n, S = 0, sum;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
		S += val[i];
	}
	sum = S / 2;
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= 0; j--) {
			if (j >= val[i]) f[j] |= f[j - val[i]];
		}
	} 
	int ans = 0;
	for (int i = 0; i <= sum; i++) {
		if (f[i]) ans = i; 
	}
	cout << ans << " " << S - ans << endl;
	return 0;
} 
