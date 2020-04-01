#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m, x, y;
char mmap[105][105];
int dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1,
				1, 1, 1, -1, -1, 1, -1, -1};


int main() {
	//注意根据题目要求输入数据 
	cin >> m >> n >> y >> x;
	//以坐标轴的顺序输入字符 
	for (int i = 1; i <= n; i++) {
		cin >> &mmap[i][1];
	}
	queue<node> que;
	//处理数据下标 
	que.push({n - x + 1, y, 0});
	mmap[n - x + 1][y] = '*';
	int ans;
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		ans = temp.step;
		for (int i = 0; i < 8; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (mmap[x][y] == '.') {
				mmap[x][y] = '*';//设置这样为了避免重复走 
				que.push({x, y, temp.step + 1});
			}
		}
	}
	cout << ans << endl;
	return 0;
}
