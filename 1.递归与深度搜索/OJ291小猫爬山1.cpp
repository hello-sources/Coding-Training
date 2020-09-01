/*************************************************************************
	> File Name: OJ291小猫爬山1.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 01 Sep 2020 10:09:46 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 18
int a[MAX_N + 5];
int t[MAX_N + 5], ans;
int n, w;

void dfs(int ind, int cnt) {
	if (cnt >= ans) return ;
	if (ind == n) {
		ans = cnt;
		return ;
	}
	for (int i = 0; i < cnt; i++) {
		if (t[i] < a[ind]) continue;
		t[i] -= a[ind];
		dfs(ind + 1, cnt);
		t[i] += a[ind];
	}
	t[cnt++] = w - a[ind];
	dfs(ind + 1, cnt);
	return ;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n >> w; 
	for (int i = 0; i < n; i++) cin >> a[i];
	ans = n;
	sort(a, a + n, cmp);
	dfs(0, 0);
	cout << ans << endl;
	return  0;
} 
