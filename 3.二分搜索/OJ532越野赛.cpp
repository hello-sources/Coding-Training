/*************************************************************************
	> File Name: OJ532越野赛.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 03 Aug 2020 02:30:49 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//抽象一下就是把为1的点都连接起来
//二分答案，二分的就是答案
//广搜把差值相同的都搜索一遍，直到遍历所有的1 
struct node {
	int x, y;
}; 
//raw_num1表示有几个分区点 
int sx, sy, l, r, n, m, raw_num1, mmap[505][505], eend[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int func(int mid) {
	int check[505][505] = {0};
	queue<node> que;
	que.push({sx, sy});
	int num1 = raw_num1 - 1;
	check[sx][sy] = 1;
	while (!que.empty()) {
		if (num1 == 0) break;
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {//四个方向 
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x == 0 || y == 0 || x > n || y > m) continue;
			if (check[x][y] == 0 && abs(mmap[temp.x][temp.y] - mmap[x][y]) <= mid) {
				check[x][y] = 1;
				que.push({x, y});
				if (eend[x][y] == 1) num1--;//是分区点，num就对应减一 
			}
		}
	}
	if (num1 == 0) return 1;
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			r = max(r, mmap[i][j]);//右值更新为最大值 
		}
	}	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> eend[i][j];
			if (eend[i][j] == 1) {//记录原始有多少的1 
				raw_num1++;
				sx = i;
				sy = j;
			}
		}
	}
	//00000000011111111111找第一个1的问题	
	while (l != r) {
		int mid = (l + r) >> 1;
		if (func(mid)) {//根据mid能把所有的分区点连起来 
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
} 
