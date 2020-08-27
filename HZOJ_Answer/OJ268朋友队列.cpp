/*************************************************************************
	> File Name: OJ368朋友队列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 27 Aug 2020 08:18:38 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define MAX_N 1000

map<int, int> q_ind;
queue<int> main_q;
queue<int> q[MAX_N + 5]; 

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			q_ind[a] = i;
		}
	} 
	string op;
	while (cin >> op) {
		if (op == "STOP") break;
		if (op == "ENQUEUE") {
			int x;
			cin >> x;
			q[q_ind[x]].push(x);
			if (q[q_ind[x]].size() == 1) main_q.push(q_ind[x]);
		} else {
			cout << q[main_q.front()].front() << endl;
			q[main_q.front()].pop();
			if (q[main_q.front()].empty()) main_q.pop();
		}
	}
	return 0;
}
