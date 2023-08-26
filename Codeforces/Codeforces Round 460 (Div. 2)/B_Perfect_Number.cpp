#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int K;
	cin >> K;
	int cnt = 0;
	for (long long i = 19; i <= 1111111111; i++) {
		long long tmp = i;
		int sum = 0;
		while (tmp) {
			sum += tmp % 10;
			if (sum > 10)
				break;
			tmp /= 10;
		}
		if (sum == 10) {
			cnt++;
			if (cnt == K) {
				cout << i << '\n';
				return 0;
			}
		}
	}
}