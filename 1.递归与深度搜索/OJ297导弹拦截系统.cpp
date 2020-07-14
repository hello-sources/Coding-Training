/*************************************************************************
	> File Name: OJ297导弹拦截系统.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 14 Jul 2020 01:38:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int n, num[55], dep;
vector<int> up, down;

bool dfs(int x) {
	if (up.size() + down.size() > dep) return 0;
	if (x == n + 1) return 1;
	int cnt = 0, t;
	for (int i = 0; i < up.size(); i++)
		if (up[i] < num[x] && up[i] > cnt) {
			cnt = up[i];
			t = i;
		}
	if (cnt) {
		up[t] = num[x];
		if (dfs(x + 1)) return 1;
		up[t] = cnt;
	} else {
		up.push_back(num[x]);
		if (dfs(x + 1)) return 1;
		up.pop_back();
	}
	cnt = 2100000000;
	for (int i = 0; i < down.size(); i++)
		if (down[i] > num[x] && down[i] < cnt) {
			cnt = down[i];
			t = i;
		}
	if (cnt != 2100000000) {
		down[t] = num[x];
		if (dfs(x + 1)) return 1;
		down[t] = cnt;
	} else {
		down.push_back(num[x]);
		if (dfs(x + 1)) return 1;
		down.pop_back();
	}
	return 0;
}

int main() {
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    while (dfs(1) == 0) {
        ++dep;
    }
	cout << dep << endl;
	return 0;
}
