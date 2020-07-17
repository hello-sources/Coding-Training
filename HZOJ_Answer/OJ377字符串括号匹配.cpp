/*************************************************************************
	> File Name: OJ377字符串括号匹配.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 17 Jul 2020 12:48:50 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std; 

int main() {
	char str[305];
	stack<int> sta;//建立栈 
	cin >> str;//读入字符串 
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
			sta.push(i);//对应左括号入栈 
		} else if (str[i] == ')') {//对于是右括号的情况 
			if (sta.empty()) {//判断栈空，如果为空就表示不对 
				cout << "NO" << endl;
				return 0;
			} else {
				sta.pop();//否则出队操作 
			}
		}
	}
	if (sta.empty()) {
		cout << "YES" << endl;//栈空表示匹配完全了 
	} else {
		cout << "NO" << endl;
	}
	
	return 0; 
}
