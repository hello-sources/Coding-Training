/*************************************************************************
	> File Name: OJ287合并果子.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 12 Jul 2020 07:31:40 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	//建立权值小的优先队列，权值小的优先级高 
	priority_queue<int, vector<int>, greater<int> > que;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		que.push(t);//定义临时变量存储果子质量 
	}
	//不是一堆就一直合并 
	while (que.size() != 1) {
		int t = que.top();//最小的
		que.pop();
		t += que.top();
		que.pop();//次小的加一起 
		ans += t;
		que.push(t);//把对应结果再入队 
	}
	cout << ans << endl;
	return 0;
} 
