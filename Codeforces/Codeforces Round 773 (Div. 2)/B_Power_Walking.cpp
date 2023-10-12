#include<bits/stdc++.h>
using namespace std;

set<int> type;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int input, n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &input);
			type.insert(input);
		}
		int output = type.size();
		printf("%d", output);
		for (int i = 2; i <= n; i++) printf(" %d", output > i ? output : i);
		printf("\n");
		if (t) type.clear();
	}
	return 0;
}