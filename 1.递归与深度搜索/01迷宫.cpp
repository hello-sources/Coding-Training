#include <iostream>
#include <queue>
using namespace std;
//记录节点位置 
struct node {
	int x, y;
};

int n, m, k, ans;
char mmap[3005][3005];
int check[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; 
queue<node> que;//初始化一个队列 

void func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		//方向数组判断是否能越界以及对应的标记元素是否为0 
		if (check[tx][ty] == 0 && mmap[tx][ty] != mmap[x][y] && mmap[tx][ty]) {
			ans++;//更新答案 
			check[tx][ty] = 1;//标记位置为1 
			que.push({tx, ty});//位置入队 
			func(tx, ty);//递归求解 
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> (&mmap[i][1]);//对于字符二维数组一层循环输入方法 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] == 0) {// 标记数组的引入，如果没被使用 
				ans = 1;//答案从1开始 
				check[i][j] = 1;//标记数组置为1 
				que.push({i, j});//相应的位置进行入队 
				func(i, j);//递归求解操作 
				while (!que.empty()) {//队列非空的时候，说明该点已经求解完了 
					node temp = que.front();
					que.pop();//队列所有元素出栈 
					check[temp.x][temp.y] = ans;//对应标记位置上面的值为相应的答案 
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;//输入相应的组元素 
		cin >> a >> b;
		cout << check[a][b] << endl;//输出记录的相应的元素 
	}
	return 0;
}
