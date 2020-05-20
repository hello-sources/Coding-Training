/*************************************************************************
    > File Name: 520等式.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 09:38:25 PM CST
 ************************************************************************/



#include <iostream>
using namespace std;

long long a, num[15000005]; 

int main() {
	cin >> a;
	for (int i = 1; i <= 15000000; i++) {
		num[i] = num[i - 1] + i;
	}
	for (int i = a; ; i++) {
		int l = 1, r = 15000000;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (num[mid] - num[i] == num[i - 1]) {
				cout << i << " " << mid << endl;
				return 0;
			}
			if (num[mid] - num[i] > num[i - 1]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} 
	}
	return 0;
}
