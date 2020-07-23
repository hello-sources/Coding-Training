/*************************************************************************
	> File Name: OJ470最小差值.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 23 Jul 2020 02:55:20 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int num[500005], n;
//num数组是用来存储转换后的十进制数据 

int main() {
	char str[10];
	while (cin >> str) {
		//倒着把数转换为十进制数 
		for (int i = 4, j = 1; i >= 0; i--, j*= 36) {
			int temp;
			if (str[i] <= '9') {
				temp = str[i] - '0';
			} else {
				temp = str[i] - 'A' + 10;
			}
			num[n] += temp * j;
		}
		n++;
	}
	sort(num, num + n);//对于保存的十进制数据进行排序 
	int mmin = 999999999;
	for (int i = 0; i < n - 1; i++) {
		int temp = num[i + 1] - num[i];//找到差值最大的 
		if (temp < mmin) mmin = temp;
	}
	cout << mmin << endl;
	return 0;
} 
