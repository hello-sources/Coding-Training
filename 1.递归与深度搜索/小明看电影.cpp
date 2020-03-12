#include <iostream> 
using namespace std;
//方向数组，地图怎么存数组从1 1开始就不会有边界判断 
int n, m, sx, sy;
char mmap[505][505]; 
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

//有回溯，一次循环表示一个方向，多次循环表示多次循环 
int func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		//下面表示搜索到直接返回1 
		if (mmap[tx][ty] == 'g') return 1;
		if (mmap[tx][ty] == '.') {//如果是.表示可以走 
			//标记为一个不是.的字符，表示走过了避免重复走 
			mmap[tx][ty] = '*';
			if (func(tx, ty)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//找出起点位置赋值给x, y 
			if (mmap[i][j] == 's') {
				sx = i;
				sy = j;
			}
		}
	}
	if (func(sx, sy)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return  0;
}
