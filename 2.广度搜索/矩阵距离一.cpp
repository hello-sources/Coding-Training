#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m;
char mmap[1005][1005];
int ans[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int main() {
	cin >> n >> m;
	queue<node> que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//从1开始找找到最近的0 
			//我们采用从1开始找，这样减少运算量，提高解题速度 
			if (mmap[i][j] == '1') {
				que.push({i, j, 0});
				ans[i][j] = -1; //同时把答案数组标记为-1，便于后面处理答案 
			}
		}
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			//判断是否越界 
			if (x < 1 || y < 1 || x > n || y > m || ans[x][y]) continue;
			ans[x][y] = temp.step + 1;//对应步数加一存到结构体中 
			que.push({x, y, ans[x][y]});//相应的元素入队 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j != 1) cout << " ";
			if (ans[i][j] == -1) {//判断是否为-1 ，如果为-1就输出0 
				cout << 0;
			} else {
				cout << ans[i][j];//否则输出就是答案数组 
			}
		}
		cout << endl;
	}
	return 0;
} 
