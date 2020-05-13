/*************************************************************************
    > File Name: 最大整数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 07:00:29 PM CST
 ************************************************************************/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string str[100005];

bool cmp(string a, string b) {
	return a + b > b + a;//c++重载了加法这个运算方法 
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << str[i];
	}
	cout << endl;
	return 0;
} 
