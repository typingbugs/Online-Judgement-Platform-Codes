#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	double m = 1e11, a, b, M;
	cin >> N >> M;
	while (N--) {
		cin >> a >> b;
		m = min(a / b, m);
	}
	printf("%.8lf\n", m * M);
	return 0;
}