#include <iostream>
using namespace std;

int cnt, num[10]; 

void p() {
	for (int i = 0; i < cnt; i++) {
		if (i) cout << "+";
		cout << num[i];
	}
	cout << endl;
}

//函数传入参数有剩余数值，以及剩余要统计的数 
int func(int s, int left_num, int left_cnt) {
	if (left_cnt == 0) { 
		if (left_num == 0) {
			p();
			return 1;
		}
		//对于剩余数为0以及剩余次数为0，则返回1表示找到一种方法 
		return 0;//否则就剩下的数就没有必要进行操作了 
	}
	int ans = 0;//统计次数 
	for (int i = s; i <= left_num; i++) {
		num[cnt++] = i;
		ans += func(i, left_num  - i, left_cnt - 1);
		cnt--;
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	//传入参数从一开始 
	cout << func(1, n, m) << endl;
	return 0;
}
