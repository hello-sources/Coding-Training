#include <iostream>
using namespace std;

int n, weight[20], cnt, mark[1005] = {1};

//传入两个参数分别是开始数，以及总质量 
void func(int start, int sum) {
	if (!mark[sum]) {
		cnt++;
		mark[sum] = 1;
		//进行查重操作，判断对应标记数组数是否为1
		//否则进行对应结果加一 
	}
	for (int i = start; i < n; i++) {
		sum += weight[i];
		func(i + 1, sum);//递归 
		sum -= weight[i];//回溯 
	}
	return ;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	func(0, 0);
	cout << cnt << endl;
	return 0; 
} 
