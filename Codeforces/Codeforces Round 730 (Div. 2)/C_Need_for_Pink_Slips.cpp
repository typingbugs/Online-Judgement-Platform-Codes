//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

#define eps 1e-8

void solve();

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(12);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}

int times, valid;
double cmp[3], v, ans, pro;

void dfs(int cur){
	if (cur == 2) {
		ans += (times + 1) * pro * cmp[cur];
		return;
	}
	else {
		times++;
		pro *= cmp[cur];
		double temp[3] = { 0 };
		if (cmp[cur] - v > eps) {
			cmp[cur] += (temp[cur] = -v);
			for (int j = 0; j < 3; j++) {
				if (cmp[j] >= eps && j != cur) {
					cmp[j] += (temp[j] = v / (valid - 1));
				}
			}
		}
		else {
			cmp[cur] += (temp[cur] = -cmp[cur]);
			for (int j = 0; j < 3; j++) {
				if (cmp[j] >= eps && j != cur) {
					cmp[j] += (temp[j] = -temp[cur] / (valid - 1));
				}
			}
			valid--;
		}

		for (int i = 0; i < 3; i++) {
			if (cmp[i] > eps) {
				dfs(i);
			}
		}

		for (int j = 0; j < 3; j++) {
			cmp[j] -= temp[j];
		}
		if (cmp[cur] - v < eps) {
			valid++;
		}
		pro /= cmp[cur];
	}
	times--;
}

void solve(){
	times = 0;
	valid = 0;
	ans = 0;
	pro = 1;
	for (int i = 0; i < 3; i++) {
		cin >> cmp[i];
		if (cmp[i] > 0) {
			valid++;
		}
	}
	cin >> v;
	for (int i = 0; i < 3; i++) {
		if (cmp[i] > eps) {
			dfs(i);
		}
	}
	cout << ans << '\n';
}