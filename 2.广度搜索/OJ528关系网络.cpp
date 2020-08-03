/*************************************************************************
	> File Name: OJ528关系网络.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 03 Aug 2020 02:06:58 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

//自定义结构体表示对应的数值以及需要的中间人数 
struct node {
	int num, ans;
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
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 1; i <= n; i++) {//遍历整个队列 
			if (num[temp.num][i] == 1 && check[i] == 0) {
				if (i == y) {
					cout << temp.ans << endl;
					return 0;
				}
				que.push({i, temp.ans + 1});
				check[i] = 1;
			}
		}
	}	
	cout << 0 << endl;
	return 0;
} 
