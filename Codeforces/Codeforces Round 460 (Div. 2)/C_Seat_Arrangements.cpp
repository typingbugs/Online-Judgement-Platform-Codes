#include <cstdio>
using namespace std;

bool s[2005][2005];

int main() {
	int n, m, K;
	long long ans = 0;
	scanf("%d %d %d\n", &n, &m, &K);
	char in;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((in = getchar()) == '.') {
				s[i][j] = 1;
			}
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m - K; j++) {
			int k = 0;
			while (s[i][j + k] && j + k < m) {
				k++;
			}
			ans += (k - K >= 0) ? k + 1 - K : 0;
			j += k;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= n - K; j++) {
			int k = 0;
			while (s[j + k][i] && j + k < n) {
				k++;
			}
			ans += (k - K >= 0) ? k + 1 - K : 0;
			j += k;
		}
	}
	if (K == 1) {
		ans /= 2;
	}
	printf("%lld\n", ans);
	return 0;
}