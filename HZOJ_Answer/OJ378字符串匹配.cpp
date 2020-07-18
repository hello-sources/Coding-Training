/*************************************************************************
	> File Name: OJ378字符串匹配.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 18 Jul 2020 09:33:04 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> sta;//建立栈
	char str[305];
	cin >> str;
	for (int i = 0; str[i]; i++) {
	 	if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
	 		sta.push(str[i]);
		}
		if (str[i] == ')') {
			if (sta.top() == '(') {
		 		sta.pop();
			} else {
			 	cout << "NO" << endl;
			 	return 0;
			}
		}
		if (str[i] == ']') {
			if (sta.top() == '[') {
		 		sta.pop();
			} else {
			 	cout << "NO" << endl;
			 	return 0;
			}
		}
		if (str[i] == '}') {
			if (sta.top() == '{') {
		 		sta.pop();
			} else {
			 	cout << "NO" << endl;
			 	return 0;
			}
		}
	}
	if (sta.empty()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
