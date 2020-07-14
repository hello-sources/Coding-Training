/*************************************************************************
	> File Name: OJ302推箱子游戏.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 14 Jul 2020 02:21:01 PM CST
 ************************************************************************/

#include <iostream>
#include <queue> 
#include <cstring>
using namespace std;

//记录状态：0立着1横躺着2竖躺着 
struct node {
	int x, y, step, status;
	//分别表示对应的坐标，到这需要几步，还有就是对应状态 
}; 

int n, m, sx, sy, sx2, sy2, status;
char mmap[550][550];
//分别对应三种状态四个方向，每一个状态两种方式 
int dir[3][4][2] = {
	-2, 0, 0, -2, 0, 1, 1, 0,
	-1, 0, 0, -1, 0, 2, 1, 0,
	-1, 0, 0, -1, 0, 1, 2, 0 
};
//表示三种不同状态往四个方向走，新生成的形状的状态 
int sta_num[3][4] = {
	2, 1, 1, 2,
	1, 0, 0, 1,
	0, 2, 2, 0
};
int check_num[3][550][550];

int check(node &t) {
	if (check_num[t.status][t.x][t.y] == 1) {
		return 0;
	}
	if (t.status == 0) {
		if (mmap[t.x][t.y] == '.') {
			return 1;
		}
		return 0;
	}
	if (t.status == 1) {
		if ((mmap[t.x][t.y] == '.' || mmap[t.x][t.y] == 'E') && 
		(mmap[t.x][t.y + 1] == '.' || mmap[t.x][t.y + 1] == 'E')) {
			return 1;
		}
		return 0;
	}
	if ((mmap[t.x][t.y] == '.' || mmap[t.x][t.y] == 'E') && 		
	(mmap[t.x + 1][t.y] == '.' || mmap[t.x + 1][t.y] == 'E')) {
		return 1;
	}
	return 0;
}

int main() {
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		status = 0;//初始状态为0 
		memset(check_num, 0, 3 * 550 * 550 * sizeof(int));
		memset(mmap, 0, 550 * 550 * sizeof(char));
		queue<node> que;//初始队列
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> mmap[i][j];
				//记录起点位置 
				if (mmap[i][j] == 'X' && status == 0) {
					status++;
					sx = i;
					sy = j; 
				} else if (mmap[i][j] == 'X' && status == 1) {
					//对应两个起点
					status++;
					sx2 = i;
					sy2 = j;
				}
			}
		} 
		if (status == 1) {
			status = 0;//如果是横，状态为0 
		} else if (sx == sx2) {
			status = 1;//横躺着 
		} else {
			status = 2;//竖躺着 
		}
		que.push({sx, sy, 0, status});//入队
		check_num[status][sx][sy] = 1;
		int flag = 0;
		//搜索 
		while (!que.empty()) {
			node temp = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				node t2;
				t2.x = temp.x + dir[temp.status][i][0];
				t2.y = temp.y + dir[temp.status][i][1];
				t2.step = temp.step + 1;
				t2.status = sta_num[temp.status][i];
				if (t2.x < 1 || t2.y < 1 || t2.x > n || t2.y > m) {
					continue;//边界判断 
				}
				if (mmap[t2.x][t2.y] == 'O' && t2.status == 0) {
					cout << t2.step << endl;
					flag = 1;
					break;
				} 
				if (check(t2)) {
					check_num[t2.status][t2.x][t2.y] = 1;
					que.push(t2);
				}
			}
			if (flag == 1) {
				break;
			}
		} 
		if (flag == 0) {
			cout << "Impossible" << endl;
		}
	}
	
	return 0;
} 
