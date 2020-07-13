/*************************************************************************
	> File Name: OJ290可达性统计.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 13 Jul 2020 08:50:57 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <bitset>
using namespace std;

int num[30005], ans[30005];
vector<int> e[30005], a;
bitset<30005> b[30005];
queue<int> q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		num[y]++;
		b[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            q.push(i);
        }
    }
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		a.push_back(x);
		for (int i = 0; i < e[x].size(); i++) {
			int y = e[x][i];
            num[y]--;
			if (num[y] == 0) q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
        b[i][i] = 1;
    }
	for (int i = a.size() - 1; i >= 0; i--) {
		int x = a[i];
		for (int j = 0; j < e[x].size(); j++) {
			b[x] |= b[e[x][j]];
        }
		ans[x] = b[x].count();
	}
	for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
	return 0;
}
