/*************************************************************************
	> File Name: OJ580明明的随机数.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 15 Aug 2020 08:31:27 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s.insert(t);
	}
	cout << s.size() << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
