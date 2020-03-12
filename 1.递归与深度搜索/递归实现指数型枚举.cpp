#include <iostream>
using namespace std;

int n, mark[14], num[15], cnt;

void func(int left) {
	if (left == 0) {
		for (int i = 0; i < cnt; i++) {
			if (i) cout << " ";
			cout << num[i];
		}
		cout << endl;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
		 	mark[i] = 1; 
			num[cnt++] = i;
			func(left - 1);
			cnt--;
			mark[i] = 0;
		} 
	}
}

int main() {
	cin >> n;
	func(n);
	return 0;
}
