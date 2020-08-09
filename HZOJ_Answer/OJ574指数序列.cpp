/*************************************************************************
	> File Name: OJ574指数序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 09 Aug 2020 08:34:40 PM CST
 ************************************************************************/

#include <iostream>
#include <set> 
using namespace std;

int n, ans;
set<int> se;

void my_insert(int x) {
	if (se.find(x) == se.end()) {
		se.insert(x); 
	} else {
		se.erase(x);
		my_insert(x + 1);
	}
}

int main() {
	cin >> n;
	se.insert(-1);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		my_insert(t);
	} 
	set<int>::iterator it, it2;
	it = it2 = se.begin();
	it2++;
	for ( ; it2 != se.end(); it++, it2++) {
		ans += (*it2 - *it - 1);
	}
	cout << ans << endl;
	return 0;
}
