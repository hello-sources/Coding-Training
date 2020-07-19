/*************************************************************************
	> File Name: OJ387敲七.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 19 Jul 2020 09:24:56 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std; 

int have7(int x) {
	if (x % 7 == 0) return 1;
	while (x) {
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

int main() {
	int n, x, t;
	cin >> n >> x >> t;
	queue<int> que;
	for (int i = x; i <= n; i++) {
		que.push(i);//先从第x个开始入队 
	}
	for (int i = 1; i < x; i++) {
		que.push(i);//然后从第一个入队到x 
	}
	while (que.size() != 1) {
		if (have7(t) == 1) {
			que.pop();//与7有关直接出队列 
		} else {
			que.push(que.front());//否则直接把开头入队列 
			que.pop();//然后出队，形成一个循环 
		}
		t++;//对应数值加一 
	}
	cout << que.front() << endl;//输出第一个编号 
	return 0;
} 
