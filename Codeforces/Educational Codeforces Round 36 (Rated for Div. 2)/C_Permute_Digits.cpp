#include<bits/stdc++.h>
using namespace std;

int cnt[10], b[19], a[19];
int lena, lenb, asize;

bool cmp() {
	if (asize < lenb) {
		return false;
	}
	for (int i = 0; i < lenb; i++) {
		if (a[i] < b[i]) {
			return true;
		}
		else if (a[i] > b[i]) {
			return false;
		}
	}
	return true;
}

bool dfs(int num) {
	if (num >= 0) {
		cnt[num]--;
		a[asize++] = num;
	}
	if (cmp()) {
		if (num >= 0) {
			cnt[num]++;
			a[asize--] = 0;
		}
		return true;
	}
	if (asize < lena) {
		for (int i = 9; i >= 0; i--) {
			if (cnt[i] > 0) {
				if (dfs(i)) {
					return true;
				}
			}
		}
	}
	if (num >= 0) {
		cnt[num]++;
		a[--asize] = 0;
	}
	return false;
}

int main() {
	int in;
	char c;
	while ((c = getchar()) != '\n') {
		in = c - '0';
		cnt[in]++;
		lena++;
	}
	int cntb[10] = { 0 };
	while ((c = getchar()) != '\n') {
		in = c - '0';
		b[lenb++] = in;
		cntb[in]++;
	}
	if (lena < lenb) {
		for (int i = 9; i >= 0; ) {
			if (cnt[i] > 0) {
				printf("%d", i);
				cnt[i]--;
			}
			else {
				i--;
			}
		}
		printf("\n");
		return 0;
	}

	bool eq = 1;
	for (int i = 0; i < 10; i++) {
		if (cnt[i] != cntb[i]) {
			eq = 0;
			break;
		}
	}
	if (eq) {
		for (int i = 0; i < lenb; i++) {
			printf("%d", b[i]);
		}
		printf("\n");
		return 0;
	}

	int i = 0;
	for (; i < lenb - 1; i++) {
		if (cnt[b[i]] == 0)
			break;
		a[i] = b[i];
		cnt[a[i]]--;
	}
	for (; i >= 0; i--) {
		asize = i;
		for (int j = b[i] - 1; j >= 0; j--) {
			if (cnt[j] > 0) {
				if (dfs(j)) {
					for (int i = 0; i < lena; i++) {
						printf("%d", a[i]);
					}
					printf("\n");
					return 0;
				}
			}
		}
		cnt[a[i - 1]]++;
		a[i - 1] = 0;
	}
}

//int main() {
//	int a[19], len = 0;
//	U64 b;
//	set<int> s;
//	char tmp;
//	while ((tmp = getchar()) != '\n') {
//		a[len] = tmp - '0';
//		s.insert(a[len]);
//		len++;
//	}
//	sort(a, a + len);
//	int a1[19];
//	for (int i = 0; i < len; i++) {
//		a1[i] = a[i];
//	}
//
//	scanf("%llu", &b);
//	U64 temp = 1;
//	for (int i = 0; i < len; i++) {
//		temp *= 10;
//	}
//	temp /= 2;
//	bool big = b > temp;
//
//	temp = 0;
//	for (auto iter = s.begin(); iter != s.end(); iter++) {
//		int pos = lower_bound(a, a + len, *iter) - a;
//		for (; pos > 0; pos--) {
//			a[pos] = a[pos - 1];
//		}
//		a[0] = *iter;
//		for(int i = len;)
//	}
//	return 0;
//}