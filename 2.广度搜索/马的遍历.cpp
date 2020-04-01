#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m, sx, sy;
int mmap[405][405];
//根据马走日的方向数组 
int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1,
					-1, 2, -1, -2, -2, 1, -2, -1};

int main() {
	cin >> n >> m >> sx >> sy;
	queue<node> que;
	que.push({sx, sy, 0});
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 8; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x < 1 || y < 1 || x > n || y > m || mmap[x][y]) continue;
			if (mmap[x][y] == 0) {
				mmap[x][y] = temp.step + 1;
				que.push({x, y, temp.step + 1});
			}
		}
	}
	mmap[sx][sy] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j != 1) cout << " ";
			if (i == sx && j == sy) {
				cout << 0;
			} else if (mmap[i][j] == 0) {
				cout << -1;
			} else {
				cout << mmap[i][j];
			}
		}
		cout << endl;
	}
	return 0;
} 
