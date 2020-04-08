#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct node {
	int x, y;
};

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int n, m, cnt;
char mmap[55][55];
int check[55][55];

int main() {
	cin >> n >> m;
	queue<node> que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			if (mmap[i][j] == '*') {
				que.push({i, j});
				mmap[i][j] = '.';
				check[i][j] = 1;
			}
		}
	}
	cin >> cnt;
	while (cnt--) {
		string t;
		cin >> t;
		int dir_num;//判断是否是东西南北 
		if (t == "NORTH") {
			dir_num = 0;
		} else if (t == "SOUTH") {
			dir_num = 1;
		} else if (t == "WEST") {
			dir_num = 2;
		} else {
			dir_num = 3;
		}
		memset(check, 0, sizeof(check));//每一层去重数组标记为0 
		int times = que.size();//记录每一层的数 
		for (int i = 0; i < times; i++) {
			node temp = que.front();
			que.pop();
			for (int j = 1; 1; j++) {
				int x = temp.x + j * dir[dir_num][0];
				int y = temp.y + j * dir[dir_num][1];
				if (mmap[x][y] != '.') break;
				if (!check[x][y]) {
					que.push({x, y});
					check[x][y] = 1; 
				}
			}
		}
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		mmap[temp.x][temp.y] = '*';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mmap[i][j];
		}
		cout << endl;
	}
 	
	return 0;
} 
