/*************************************************************************
	> File Name: OJ379仓库日志.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 18 Jul 2020 09:42:43 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <algorithm> 
using namespace std;

//建立两个栈，一个对应为货物多少个，第二个为数量最多的有多少个 

int main() {
	stack<int> huo, mmax;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			cin >> t;
			huo.push(t);
			if (mmax.empty()) {
				mmax.push(t);
			} else {
				mmax.push(max(mmax.top(), t));
			}
		} else if (t == 1) {
			if (!mmax.empty()) {
				huo.pop();
				mmax.pop();
			} 
		} else if (t == 2) {
			if (mmax.empty()) {
				cout << 0 << endl;
			} else {
				cout << mmax.top() << endl;
			}
		}
	} 
	
	return 0;
} 
