/*************************************************************************
	> File Name: OJ402奇怪的电梯.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 22 Jul 2020 04:15:24 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
	int now, step;
};
int n, a, b, num[205], check[205];

int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	} 
	queue<node> que;
	que.push({a, 0});
	check[a] = 1;
	while (!que.empty()) {
		node temp = que.front();
		if (temp.now == b) {
			cout << temp.step << endl;
			return 0;
		}
		que.pop();
		int up = temp.now + num[temp.now];
		int down = temp.now - num[temp.now];
		if (up <= n && check[up] == 0) {
			check[up] = 1;
			que.push({up, temp.step + 1});
		}
		if (down > 0 && check[down] == 0) {
			check[down] = 1;
			que.push({down, temp.step + 1});
		}
	}
	cout << -1 << endl;
	return 0;
} 
