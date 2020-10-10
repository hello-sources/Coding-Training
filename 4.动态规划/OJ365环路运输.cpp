/*************************************************************************
	> File Name: OJ365环路运输.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 11 Oct 2020 07:27:05 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 2000000
int a[MAX_N + 5];
int dp[MAX_N + 5];
int q[MAX_N + 5], head, tail;

inline int VAL(int i) {
	return a[i] - i;
}

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i]; 
	q[tail++] = 1;
	for (int i = 1, I = 2 * n; i <= I; i++) {
		if (i - q[head] > n / 2) head++;
		dp[i] = a[i] + a[q[head]] + (i - q[head]);
		while (tail - head && VAL(i) > VAL(q[tail - 1])) tail--;
		q[tail++] = i;
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
} 
