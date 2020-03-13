#include <iostream>
#include <algorithm>
using namespace std;

int n, x, num[45], set[2][3000005], cnt[2];

void func(int s_no, int s, int e, int sum) {
	if (sum > x) return ;
//	int flag = 0;
	for (int i = s; i < e; i++) {
		sum += num[i];
		set[s_no][cnt[s_no]] = sum;//�Ұ벿������С��x����� 
		cnt[s_no]++;//ͳ���Ұ벿���ж������С��x 
		func(s_no, i + 1, e, sum);//�ݹ����� 
		sum -= num[i];//���� 
	}
//	return flag;
} 

int main() {
	while (cin >> n >> x) {
		cnt[0] = cnt[1] = 1;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		func(0, 0, n / 2, 0);//�ݹ�������벿�� 
		func(1, n / 2, n, 0);//�ݹ������Ұ벿�� 
		sort(set[1], set[1] + cnt[1]);
		//ֻ����Ҫ�����Ұ벿�ֵ�������������� 
		int flag = 0;//��־λ����
		//���ֲ��ң�����������ҳ�һ���������ұ������ҵ��Ƿ��������֮�͵���x������� 
		for (int i = 0; i < cnt[0]; i++) {
			int target = x - set[0][i];
			int l = 0, r = cnt[1] - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (set[1][mid] == target) {
					cout << "YES" << endl;//�ҵ���ֱ������ѭ�� 
					flag = 1;//��Ӧ��־λ����1 
					break;
				} else if (set[1][mid] < target) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			if (flag) break;
		}
		!flag && cout << "NO" << endl;
//		if (func(0, 0)) cout << "YES" << endl;
//		else cout << "NO" << endl;
	}	
	return 0;
}
