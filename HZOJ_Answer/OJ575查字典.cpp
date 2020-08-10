/*************************************************************************
	> File Name: OJ575查字典.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 10 Aug 2020 08:06:45 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		int t1;
		cin >> t >> t1;
		m[t] = t1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		cout << m[t] << endl;
	}
	return 0;
} 
