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

//�������������ʣ����ֵ���Լ�ʣ��Ҫͳ�Ƶ��� 
int func(int s, int left_num, int left_cnt) {
	if (left_cnt == 0) { 
		if (left_num == 0) {
			p();
			return 1;
		}
		//����ʣ����Ϊ0�Լ�ʣ�����Ϊ0���򷵻�1��ʾ�ҵ�һ�ַ��� 
		return 0;//�����ʣ�µ�����û�б�Ҫ���в����� 
	}
	int ans = 0;//ͳ�ƴ��� 
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
	//���������һ��ʼ 
	cout << func(1, n, m) << endl;
	return 0;
}
