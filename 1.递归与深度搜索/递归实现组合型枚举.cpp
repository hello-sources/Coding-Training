#include <iostream>
using namespace std;

int n, m, num[15], cnt;

//��������ǿ�ʼ�������Լ�ʣ�µ��� 
void func(int s, int left) {
	if (left == 0) {//ʣ����Ϊ0˵��ѡ���ˣ�ֱ����� 
		for (int i = 0; i < cnt; i++) {
			if (i) cout << " ";
			cout << num[i];
		}
		cout << endl;
		return ;
	}
	//i��������Ϊn-left+1��Ϊ�˱��ⲻ��Ҫ�Ķ�����������裬�Խ�ʡʱ�� 
	for (int i = s; i <= n - left + 1; i++) {
		num[cnt++] = i;
		func(i + 1, left - 1);//��һ���i+1��ʼ����Ӧʣ�����Ҫ��ȥ1 
		cnt--;
	}
}


int main() {
	cin >> n >> m;
	func(1, m);
	return 0;
}
