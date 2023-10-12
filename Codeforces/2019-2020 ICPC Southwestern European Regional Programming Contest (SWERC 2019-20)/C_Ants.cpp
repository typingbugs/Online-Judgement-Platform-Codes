#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000006;
char a[102];
bool f[N];

int trans() {
	int res = 0;
	for (int i = 0; i < strlen(a); i++) {
		res += a[i] - '0';
		res *= 10;
	}
	res /= 10;
	return res;
}

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a[0] == '-') {
			continue;
		}
		if (strlen(a) >= 7) {
			continue;
		}
		int tmp = trans();
		if (tmp >= N) {
			continue;
		} else {
			f[tmp] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!f[i]) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}