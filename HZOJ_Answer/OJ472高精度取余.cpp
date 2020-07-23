/*************************************************************************
	> File Name: OJ472高精度取余.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 23 Jul 2020 03:04:15 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

char num[1005];
long long n, x;
//同余定理求解，假设前面几位数对应是n的倍数，那么就模n，对应结果不会变
 
int main() {
	cin >> n >> num;
	for (int i = 0; i < strlen(num); i++) {
		x = x * 10 + num[i] - '0';
		x %= n;
	}
	cout << x << endl;
	return 0;
} 
