#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, s, f;//多一个flag标记位表示是否有手机，以及是否走过 
};

int n, m, check[2005][2005];
char mmap[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
	cin >> n >> m;
	queue<node> que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//记录开始的位置 
			if (mmap[i][j] == 'S') {
				que.push({i, j, 0, 0});
				check[i][j] = 1;
			}
		}
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (temp.f == 0 && check[x][y] & 1) continue;
			if (temp.f == 1 && check[x][y] & 2) continue;
			if (temp.f == 1 && mmap[x][y] == 'T') {
				cout << temp.s + 1 << endl;
				return 0;
			}
			//去重，根据有手机无手机的状态判断是否应该加一还是二，同时利用位运算进行标记 
			if (mmap[x][y] == '.' || mmap[x][y] == 'S' || mmap[x][y] == 'T') {
				que.push({x, y, temp.s + 1, temp.f});
				check[x][y] += temp.f + 1; 
			}
			//到达小米店之后直接把对应的状态设置为3表示有手机走过了 
			if (mmap[x][y] == 'P') {
				que.push({x, y, temp.s + 1, 1});
				check[x][y] = 3;
			}
		}
	}
	return 0; 
} 
