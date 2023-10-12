#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	int ans = 0;
	if (l == 1 && r == n) printf("0\n");
	else if (l == 1) printf("%d\n", abs(r - pos) + 1);
	else if (r == n) printf("%d\n", abs(pos - l) + 1);
	else {
		if (pos <= l) printf("%d\n", r - pos + 2);
		else if (pos >= r) printf("%d\n", pos - l + 2);
		else printf("%d\n", r - l + min(r - pos, pos - l) + 2);
	}
	return 0;
}