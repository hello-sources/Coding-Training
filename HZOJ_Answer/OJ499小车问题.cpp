/*************************************************************************
	> File Name: OJ499小车问题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 31 Jul 2020 05:49:33 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

//数学问题车带着第一个人走x距离，这个人自己走到终点 
//然后车回去接另一个人，列出方程求解即可 

int main() {
	double v1, v2, s, x, ans;
	cin >> s >> v1 >> v2;
	x = (v1 + v2) * s / (3 * v1 + v2);
	ans = x / v2 + (s - x) / v1;
	printf("%.2f\n", ans);
	return 0;
}
