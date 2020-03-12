#include <iostream>
using namespace std;

//num存的是答案数组，cnt是num计数器表示记录几个数 
int n, num[15], cnt;

//按照格式输出，输出所有的num数组的数 
void p() {
	for (int i = 0; i < cnt; i++) {
		if (i) cout << " ";
		cout << num[i];
	}
	cout << endl;
}

//枚举数 
void func(int s) {
	for (int i = s; i <= n; i++) {
		num[cnt++] = i;
		//表示对应存储的数是i,对应计数器增加 
		p();//格式输出对应数组里面的数 
		func(i + 1);//递归向下一层进行搜索 
		cnt--;
		//这是进行回溯操作，如果数大于n时候，表示枚举完了，进行回退 
	}
}


int main() {
	cin >> n;
	func(1);
	return 0;
}
