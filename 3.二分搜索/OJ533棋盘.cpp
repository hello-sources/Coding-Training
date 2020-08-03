/*************************************************************************
	> File Name: OJ533棋盘.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 03 Aug 2020 02:45:35 PM CST
 ************************************************************************/

#include <iostream>
#include <queue> 
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost, last;
};
int n, m, mmap[105][105], check[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		mmap[x][y] = z + 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			check[i][j] = 99999999;
		}
	}
	queue<node> que;
	que.push({1, 1, 0, mmap[1][1]});
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		if (temp.x == m && temp.y == m) {
			check[m][m] = min(check[m][m], temp.cost);
			continue;
		}
		if (check[temp.x][temp.y] > temp.cost) {
			check[temp.x][temp.y] = temp.cost;
		} else {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x == 0 || y == 0 || x > m || y > m) continue;
			if (temp.last & 4 && mmap[x][y] == 0) continue;
			if (mmap[x][y] == 0) {//无色情况 
				que.push({x, y, temp.cost + 2 + (temp.last != 1), 5});
				que.push({x, y, temp.cost + 2 + (temp.last != 2), 6});	
			} else {
				que.push({x, y, temp.cost + (mmap[x][y] != (temp.last & 3)), mmap[x][y]});
			}
		}
	}
	if (check[m][m] == 99999999) {
		cout << -1 << endl;
	} else {
		cout << check[m][m] << endl;
	}
	return 0;
} 
