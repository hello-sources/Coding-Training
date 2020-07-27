/*************************************************************************
	> File Name: OJ482编辑.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 27 Jul 2020 11:34:29 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

char str[100005];
stack<char> fro, back;
int n; 

int main() {
	cin >> str >> n;
	for (int i = 0; str[i]; i++) {
		fro.push(str[i]);
	}
	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		if (t == 'L') {
			if (fro.empty()) continue;
			back.push(fro.top());
			fro.pop();
		} else if (t == 'D') {
			if (back.empty()) continue;
			fro.push(back.top());
			back.pop();
		} else if (t == 'B') {
			if (fro.empty()) continue;
			fro.pop();
		} else {
			cin >> t;
			fro.push(t);
		}
	}
	while (!fro.empty()) {
		back.push(fro.top());
		fro.pop();
	}
	while (!back.empty()) {
		cout << back.top();
		back.pop();
	}
	return 0;
} 
