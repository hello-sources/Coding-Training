/*************************************************************************
	> File Name: OJ500数的计算.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 31 Jul 2020 05:56:45 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int num[1005];

int func(int n) {
	if (num[n]) return num[n];
	if (n == 1) return 1;
	int sum = 1;
	for (int i = n /  2; i >= 1; i--) {
		sum += func(i);
	}
	num[n] = sum;
	return sum;
}

int main() {
	int n;
	cin >> n;
	cout << func(n) << endl;
	
	return 0;
} 
