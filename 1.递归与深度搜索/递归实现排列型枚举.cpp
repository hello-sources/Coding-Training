#include <iostream>
using namespace std;

//��ԭ�������ö�ٻ���������ʹ���˱������ 
int n, mark[14], num[15], cnt;

void func(int left) {
	//��ʣ����Ϊ0��ʾ�Ѿ�ö�����˸�ʽ������� 
	if (left == 0) {
		for (int i = 0; i < cnt; i++) {
			if (i) cout << " ";
			cout << num[i];
		}
		cout << endl;
		return ;
	}
	//��1��ʼѭ������ 
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {//���������Ϊ0��ʾδ��ʹ�ù� 
		 	mark[i] = 1; //���������Ϊ1 
			num[cnt++] = i;
			func(left - 1);
			cnt--;
			mark[i] = 0;
			//ʹ����֮��������Ϊ0����Ϊ��Ҫ����ʹ�� 
		} 
	}
}

int main() {
	cin >> n;
	func(n);
	return 0;
}
