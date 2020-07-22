/*************************************************************************
	> File Name: OJ399小明吃饭.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 22 Jul 2020 04:04:56 PM CST
 ************************************************************************/

#include <iostream>
#include <queue> 
using namespace std;

struct node {
	int x, y, step;
};
int n, m;
char mmap[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
	cin >> n >> m;
	queue<node> que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			if (mmap[i][j] == '2') {
				que.push({i, j, 0});
			}
		}
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (mmap[x][y] == '3') {
				cout << temp.step + 1 << endl;
				return 0;
			}
			if (mmap[x][y] == '.') {
				mmap[x][y] = 0;//避免重复搜索 
				que.push({x, y, temp.step + 1});
			}
		}
	}
	cout << -1 << endl;
	return 0;
} 
