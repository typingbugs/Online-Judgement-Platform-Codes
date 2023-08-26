#include <bits/stdc++.h>

using namespace std;

int main() {
	double n1, n2, n12;
	cin >> n1 >> n2 >> n12;
	printf("%d\n", (int)((n1 + 1) / (n12 + 1) * (n2 + 1) - 1));
	return 0;
}