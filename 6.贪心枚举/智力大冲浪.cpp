/*************************************************************************
    > File Name: 智力大冲浪.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 09:21:39 PM CST
 ************************************************************************/


#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int t, l;
};

int m, n, flag[100000] = {1}; //标记数组 
node item[505];

//排序规则相同损失钱数的，时间从低到高排序，否则就按照损失钱数从高到低排序 
bool cmp(node a, node b) {
	if (a.l == b.l )return a.t < b.t;
	return a.l > b.l;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> item[i].t;
	}
	for (int i = 0; i < n; i++) {
		cin >> item[i].l;
	}
	sort(item, item + n, cmp);
	for (int i = 0; i < n; i++) {
		//下面循环体就是对应的某一个游戏先判断是否玩过
		//然后根据最后剩余时间是否为0判断是否需要扣钱 
		for (int j = item[i].t; j >= 0; j--) {
			if (flag[j] == 0) {
				//如果该游戏没玩过就进行该游戏，对应标记数组改为1 
				flag[j] = 1; 
				break;
			}
			if (j == 0) {
				m -= item[i].l;//如果超过规定最后时间，就扣除对应的钱 
			}
		}
	}
	cout << m << endl;//最后的m就是剩余的钱 
	return 0;
} 
