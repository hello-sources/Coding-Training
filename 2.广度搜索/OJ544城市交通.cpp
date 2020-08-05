/*************************************************************************
	> File Name: OJ544城市交通.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 05 Aug 2020 01:44:45 PM CST
 ************************************************************************/

#include <iostream>
#include <queue> 
using namespace std;

struct node {
	int now, step;
	//优先队列自定义优先级，根据步数来划分优先级
	//重载运算符 
	bool operator< (const node &b) const {
		return step > b.step;
	}
};
int n, arr[105][105], check[105];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		} 
	}
	priority_queue<node> que;
	que.push({1, 0});
	while (!que.empty()) {
		node temp = que.top();
		que.pop();
		if (temp.now == n) {
			cout << temp.step << endl;
			return 0;
		}
		if (check[temp.now] == 1) {
			continue;
		}
		check[temp.now] = 1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0 && arr[temp.now][i]) {
				que.push({i, temp.step + arr[temp.now][i]});
			}
		}
	}
	return 0;
} 
