/*************************************************************************
	> File Name: OJ571关系网络.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 09 Aug 2020 08:26:05 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
	int now, step;
};

int n, x, y, num[105][105], check[105];

int main() {
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num[i][j];
		}
	}	
	queue<node> que;
	que.push({x, 0});
	check[x] = 1;
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		if (temp.now == y) {
			cout << temp.step - 1 << endl;
			return 0; 
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0 && num[temp.now][i]) {
				check[i] = 1;
				que.push({i, temp.step + 1});
			} 
		}
	}
	return 0;
}
