/*************************************************************************
    > File Name: 删数.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 06:46:50 PM CST
 ************************************************************************/


#include <iostream>
#include <string> 
using namespace std;

string str;
int n;
int main() {
	cin >> str >> n;
	for (int i = 0; i < n; i++) {
		int ind = str.size() - 1;
		for (int j = 0; j < str.size() - 1; j++) {
			if (str[j] > str[j + 1]) {
				ind = j;
				break;
			}
		}
		str.replace(ind, 1, "");//使用c++中的成员替换方法，中间位置表示替换长度，以及要替换为什么 
	}
	int flag = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '0') flag = 1;
		if (flag) cout << str[i];
	}
	cout << endl;
	return 0;
}
