#include <iostream>
#include <queue>
using namespace std;

//定义结构体，对应有坐标，以及步数 
struct node {
	int x, y, setp;
};

int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[505][505];
queue<node> que;//c++初始化一个队列 

void p() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mmap[i][j];
		}
		cout << endl;
	}
	cout << "---------" << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			if (mmap[i][j] == 's') {//找出开始位置，并且记录下来 
				node temp;
				temp.x = i;
				temp.y = j;
				temp.setp = 0;
				que.push({i, j, 0});//对应数据入队 
			}
		}
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (mmap[x][y] == 'g') {
				cout << temp.setp + 1 << endl;
				return 0;
			}
			if (mmap[x][y] == '.') {
				mmap[x][y] = '$';
				que.push({x, y, temp.setp + 1});
			}
		}
		p();
	}
	cout << "No" << endl;
	return 0;
} 
