#include <iostream>
using namespace std;

int calc(int n) {
	if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else if (n == 3) {
		return 1;
	} else {
		return calc(n - 3) + calc(n - 2); 
	}
}

int main() {
	int n;
	cin >> n;
	cout << calc(n) << endl;
	
	return 0;
} 
