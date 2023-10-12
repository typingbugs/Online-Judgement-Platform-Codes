#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> buk(n);
	for (int i = 0; i < n; i++) {
		cin >> buk[i];
	}
	sort(buk.begin(), buk.end());
	for (int i = n - 1; i >= 0; i--) {
		if (k % buk[i] == 0) {
			printf("%d\n", k / buk[i]);
			return 0;
		}
	}
	return 0;
}