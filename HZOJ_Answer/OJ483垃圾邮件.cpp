/*************************************************************************
	> File Name: OJ483垃圾邮件.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 28 Jul 2020 02:31:33 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int ind;
string ans[10000];

int check(int x) {
	int flag_at = 0;
	if (ans[x][0] == '.' || ans[x][ans[x].size() - 1] == '.') return 0;
	for (int i = 0; i < ans[x].size(); i++) {
		if (ans[x][i] == '@') {
			if (i == 0 || i == ans[x].size() - 1) return 0;
			flag_at++;
			if (flag_at > 1) return 0;
			if (ans[x][i - 1] == '.' || ans[x][i + 1] == '.') return 0;
		}
	}
	if (flag_at == 0) {
		return 0;
	}
	return 1;
}

int main() {
	string str;
	cin >> str;
	ans[ind++] = str;
	int f_ind = str.find("nospam");
	while (f_ind != string::npos) {
		ans[ind] = str;
		ans[ind] = str.replace(f_ind, 6, "");
		ind++;
		f_ind = str.find("nospam", f_ind + 1);
	}
	for (int i = ind - 1; i >= 0; i--) {
		f_ind = ans[i].find("at");
		while (f_ind != string::npos) {
			ans[ind] = ans[i];
			ans[ind].replace(f_ind, 2, "@");
			ind++;
			f_ind = ans[i].find("at", f_ind + 1);
		}
	} 
	sort(ans, ans + ind);
	for (int i = 0; i < ind; i++) {
		if (i > 0 && ans[i - 1] == ans[i]) continue;
		if (check(i)) cout << ans[i] << endl;
	}
	return 0;
}

