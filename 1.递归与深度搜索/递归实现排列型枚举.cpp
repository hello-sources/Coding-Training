#include <iostream>
using namespace std;

//在原先组合型枚举基础上我们使用了标记数组 
int n, mark[14], num[15], cnt;

void func(int left) {
	//当剩余数为0表示已经枚举完了格式输出即可 
	if (left == 0) {
		for (int i = 0; i < cnt; i++) {
			if (i) cout << " ";
			cout << num[i];
		}
		cout << endl;
		return ;
	}
	//从1开始循环遍历 
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {//当标记数组为0表示未被使用过 
		 	mark[i] = 1; //标记数组置为1 
			num[cnt++] = i;
			func(left - 1);
			cnt--;
			mark[i] = 0;
			//使用完之后标记数置为0，因为还要继续使用 
		} 
	}
}

int main() {
	cin >> n;
	func(n);
	return 0;
}
