#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 52;
double p[N][2];
double ans;
double x, x2;
double y, y2;

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		double tmp = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> p[j][0] >> p[j][1];
		for (int j = 1; j < n - 1; j++) {
			x = p[j][0] - p[0][0];
			x2 = p[j + 1][0] - p[0][0];
			y = p[j][1] - p[0][1];
			y2 = p[j + 1][1] - p[0][1];
			tmp += x * y2 - x2 * y;
		}
		if (tmp < 0) {
			tmp = -tmp;
		}
		tmp /= 2;
		ans += tmp;
	}
	cout << (long long)ans << endl;
	return 0;
}