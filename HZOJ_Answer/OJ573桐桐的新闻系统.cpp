/*************************************************************************
	> File Name: OJ573桐桐的新闻系统.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 09 Aug 2020 08:28:27 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue> 
using namespace std;

struct node {
	int now, raw, num;
	bool operator< (const node &b) const {
		if (now == b.now) {
			return num > b.num;
		}
		return now > b.now;
	}
};

int main() {
	priority_queue<node> que;
	string temp;
	while (cin >> temp) {
		if (temp == "#") break;
		int num, raw;
		cin >> num >> raw;
		que.push({raw, raw, num});
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node t = que.top();
		que.pop();
		cout << t.num << endl;
		t.now += t.raw;
		que.push(t); 
	}
	return 0;
}
