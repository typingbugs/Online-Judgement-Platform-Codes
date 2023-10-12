#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define N 200005
int nd[N], hv[N];
ull ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	n++;
	for (int i = 1; i <= n; i++) {
		cin >> hv[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> nd[i];
	}
	for (int i = n; i >= 1; i--) {
		int tmp = nd[i] - hv[i];
		if (tmp <= 0) {
			continue;
		}
		if (tmp % 2 == 1) {
			tmp++;
		}
		tmp /= 2;
		ans += tmp;
		nd[i - 1] += tmp;
	}
	if (nd[1] > hv[1]) {
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
	return 0;
}