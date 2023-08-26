#include<bits/stdc++.h>
using namespace std;

#define N 200001
char a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cin >> a;
	cin >> b;
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			f[i] = 0;
		}
		else if (a[i] < b[i]) {
			f[i] = 1;
		}
		else {
			f[i] = -1;
		}
	}
	unsigned long long num = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (f[i] == -1) {
			num = 0;
		}
		if (f[i] == 1) {
			num++;
			ans += num * (n - i);
			num = 0;
		}
		if (f[i] == 0) {
			num++;
		}
	}
	cout << ans << '\n';
	return 0;
}