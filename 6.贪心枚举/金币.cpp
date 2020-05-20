/*************************************************************************
    > File Name: 金币.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 06:32:44 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int x, ans = 0, num = 1, day = 0;
	cin >> x;
	while (1) {
		for (int i = 0; i < num; i++) {
			ans += num;
			day++;
			if (x == day) {
				cout << ans << endl;
				return 0;
			}
		}
		num++;
	} 
	
	return 0;
}
