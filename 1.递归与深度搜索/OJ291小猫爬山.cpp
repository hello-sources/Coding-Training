/*************************************************************************
	> File Name: OJ291小猫爬山.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 01 Sep 2020 10:07:31 AM CST
 ************************************************************************/

#include <iostream>
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

int main() {
	cin >> n >> w; 
	for (int i = 0; i < n; i++) cin >> a[i];
	ans = n;
	dfs(0, 0);
	cout << ans << endl;
	return  0;
} 
