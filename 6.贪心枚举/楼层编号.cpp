/*************************************************************************
    > File Name: 楼层编号.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 06:16:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int m, t, cnt;

int has_num(int n) {
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int temp = i; 
		while (temp) {
			if (n == (temp % 10)) {
				cnt ++;
				break;
			}
			temp /= 10;
		}
	}
	return cnt;
}

int main() {
	cin >> m >> t;
	cnt = has_num(t);
	cout << m - cnt << endl;
	
	return 0;
}
