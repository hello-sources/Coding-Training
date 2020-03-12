#include <iostream>
using namespace std;

int n, m, num[15], cnt;

//传入参数是开始的数，以及剩下的数 
void func(int s, int left) {
	if (left == 0) {//剩下数为0说明选够了，直接输出 
		for (int i = 0; i < cnt; i++) {
			if (i) cout << " ";
			cout << num[i];
		}
		cout << endl;
		return ;
	}
	//i结束条件为n-left+1是为了避免不必要的多余的搜索步骤，以节省时间 
	for (int i = s; i <= n - left + 1; i++) {
		num[cnt++] = i;
		func(i + 1, left - 1);//下一层从i+1开始，对应剩余的数要减去1 
		cnt--;
	}
}


int main() {
	cin >> n >> m;
	func(1, m);
	return 0;
}
