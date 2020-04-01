#include <iostream>
#include <queue> 
using namespace std;

struct node {
	int x, y, s, d;//增加几步以及对应的能量 
};

int n, m, d, check[105][105][105];
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; 

int main() {
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		cin >> &mmap[i][1];
	} 
	queue<node> que;
	que.push({1, 1, 0, d});//起点状态入队 
	for (int i = 0; i <= d; i++) {
		check[1][1][i] = 1;//起点状态置为1不再回来 
	} 
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			//下面的循环实现飞的部分 
			for (int j = 2; j <= temp.d; j++) {
				int x = temp.x + j * dir[i][0];
				int y = temp.y + j * dir[i][1];
				if (x == n && y == m) {//终点直接输出 
					cout << temp.s + 1 << endl;
					return 0;
				}
				//判断边界 
				if (mmap[x][y] == 0) break;
				//然后根据消耗的能量跟飞的步数判断 
				if (mmap[x][y] == 'P' && check[x][y][temp.d - j] == 0) {
					check[x][y][temp.d - j] = 1;
					que.push({x, y, temp.s + 1, temp.d - j});
				}
			}
			//下面是走的部分跟飞的部分很像 
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x == n && y == m) {
				cout << temp.s + 1 << endl;
				return 0;
			}
			if (mmap[x][y] == 'P' && check[x][y][temp.d] == 0) {
				check[x][y][temp.d] = 1;
				que.push({x, y, temp.s + 1, temp.d});
			}
		}
	}
	cout << "impossible" << endl;
	return 0;
}
