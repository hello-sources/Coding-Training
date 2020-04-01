#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m;
char mmap[200][200];
//根据马走日的方向数组 
int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1,
					-1, 2, -1, -2, -2, 1, -2, -1};


int main() {
	cin >> m >> n;
	queue<node> que;
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//判断骑士的位置然后入队操作 
			if (mmap[i][j] == 'K') {
				que.push({i, j, 0});
			}
		}
	} 
	//队列非空的时候，循环 
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 8; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x < 1 || y < 1 || x > n || y > m) continue;
			if (mmap[x][y] == 'H') {//找到终点就直接输出结果并且返回 
				cout << temp.step + 1 << endl;
				return 0;
			}
			//如果遇到点就表示没走过，标注为0，继续入队 
			if (mmap[x][y] == '.') {
				mmap[x][y] = 0;
				que.push({x, y, temp.step + 1});
			}
		}
	}	
	return 0;
} 
