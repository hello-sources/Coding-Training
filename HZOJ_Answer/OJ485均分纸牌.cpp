/*************************************************************************
	> File Name: OJ485均分纸牌.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 29 Jul 2020 11:14:02 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int n, num[105] = {0}, sum = 0, avg;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	avg = sum / n;
	int ans = 0;
	//利用平均值，模型理想化对应纸牌可以为负数
	//就是前一位移动相应纸牌之后对应的，该纸牌堆对应纸牌数可能为负
	//但是考虑到后面的牌堆肯定能补齐，所以不考虑牌堆为负数的情况 
	for (int i = 0; i < n - 1; i++) {
		if (num[i] != avg) {
			ans++;
			num[i + 1] += num[i] - avg;
			num[i] = avg;
		}
	}
	cout << ans << endl;
	return 0;
} 
