/*************************************************************************
    > File Name: 两数之和.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 08:13:02 PM CST
 ************************************************************************/


#include <iostream>
using namespace std;

int n, num[10000005], target;

int main() {
	cin >> n >> target;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int l = 0, r = n - 1;
	while (l < r) {
		int sum = num[l] + num[r];
		if (sum == target) {
			cout << l << " " << r << endl;
			return 0;
		}
		if (sum < target) {
			l++;
		} else {
			r--;
		}
	}
	return 0;
}
