/*************************************************************************
	> File Name: OJ229开门.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 06 Jul 2020 11:00:51 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

//广搜，用位记录状态，对应状态结构
struct node {
	int num, step;
};

//对应最多16位状态
int num[4][4] = {
	1, 2, 4, 8,
	16, 32, 64, 128,
	256, 512, 1024, 2048,
	4096, 8192, 16384, 32768
};
int check[100000];//对应广搜去重数组

int main() {
	int start = 0;//定义初始状态
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char t;
			cin >> t;
			//当对应字符为+号，就加上对应状态数组的值
			if (t == '+') start += num[i][j];
		}
	}
	queue<node> que;
	que.push({start, 0});//把起点插入队列
	check[start] = 1;//起点数组值为一，避免重复搜索
	while (!que.empty()) {//队列不为空
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				node temp = que.front();//每次拿出对首元素进行搜索
				if (temp.num & num[i][j]) {//位运算是+号
					temp.num -= num[i][j];//变成-号
				} else {
					temp.num += num[i][j];//否则变成+号
				}
				//处理同行同列
				for (int k = 0; k < 4; k++) {//对应处理列
					if (temp.num & num[i][k]) {
						temp.num -= num[i][k];
					} else {
						temp.num += num[i][k];
					}
					if (temp.num & num[k][j]) {//对应处理行
						temp.num -= num[k][j];
					} else {
						temp.num += num[k][j];
					}
				}
				temp.step++;//处理完变换问题就步数加一
				if (temp.num == 0) {//当temp的num全为0表示全为-号
					cout << temp.step << endl;
					return 0;
				}
				//如果对应的点没被搜过，就插入到队列里面
				if (check[temp.num] == 0) {
					check[temp.num] = 1;
					que.push(temp);
				}
			}
		}
		que.pop();//表示按照(i,j)为起点的数都搜索过了
	}

	return 0;
}
