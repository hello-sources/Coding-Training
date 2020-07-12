/*************************************************************************
	> File Name: OJ283拨号.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 12 Jul 2020 07:19:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[10005];//用string存储字符串 


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);//从小到大排序，处理9999，以及99的问题 
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i].find(s[j]) == 0) {//对应的如果没有对应前缀 
				cout <<  "NO" << endl;//输出no然后结束程序 
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
} 
