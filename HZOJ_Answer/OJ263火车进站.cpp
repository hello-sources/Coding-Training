/*************************************************************************
	> File Name: OJ263火车进站.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 26 Aug 2020 06:56:55 AM CST
 ************************************************************************/

#include <iostream>
#include <stack> 
#include <algorithm>
using namespace std;
#define MAX_N 20
int arr[MAX_N + 5];

bool is_valid(int *arr, int n) {
	stack<int> s;
	int temp = 0;//记录一个数字，代表当前栈中已经入栈的最大的数字 
	for (int i = 0; i < n; i++) {
		while (temp < arr[i]) s.push(++temp);
		if (s.top() - arr[i]) return false;//栈顶元素不等于待出栈的元素表示非法 
		s.pop();
	}	
	return true;
}

int main() {
	int n, cnt = 20;
	cin >> n;
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	do {
		if (is_valid(arr, n)) {//如果arr数组是一个合法的出栈序列 
			for (int i = 0; i < n; i++) {
				cout << arr[i];
			}
			cout << endl;
			cnt--;
		}
	} while (next_permutation(arr, arr + n) && cnt);//找到下一个全排列，且cnt不为0 
	return 0;
} 
