//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<iomanip>
#include<bits/stdc++.h>
using namespace std;

#define eps 1e-8

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(12);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

struct Node {
	int cur, times, valid;
	double cmp[3], pro;
};

double v, ans;
queue<Node*> q;

void bfs() {
	while (q.empty() != 1) {
		Node* now = new Node;
		now = q.front();
		q.pop();
		int cur = now->cur;
		if (cur == 2) {
			ans += (now->times + 1) * now->pro * now->cmp[2];
		}
		else {
			now->pro *= now->cmp[cur];
			if (now->cmp[cur] - v > eps) {
				now->cmp[cur] += -v;
				for (int j = 0; j < 3; j++) {
					if (now->cmp[j] >= eps && j != cur) {
						now->cmp[j] += v / (now->valid - 1);
					}
				}
			}
			else {
				double temp;
				now->cmp[cur] += (temp = -now->cmp[cur]);
				for (int j = 0; j < 3; j++) {
					if (now->cmp[j] >= eps && j != cur) {
						now->cmp[j] += -temp / (now->valid - 1);
					}
				}
				now->valid--;
			}
			now->times++;
			for (int i = 0; i < 3; i++) {
				if (now->cmp[i] > eps) {
					Node* node = new Node;
					node->cur = i;
					node->times = now->times;
					node->valid = now->valid;
					node->pro = now->pro;
					for (int j = 0; j < 3; j++) {
						node->cmp[j] = now->cmp[j];
					}
					q.push(node);
				}
			}
		}
	}
}

void solve() {
	ans = 0;
	double cmp[3];
	int valid = 0;
	for (int i = 0; i < 3; i++) {
		cin >> cmp[i];
		if (cmp[i] > 0) {
			valid++;
		}
	}
	cin >> v;

	for (int i = 0; i < 3; i++) {
		Node* node = new Node;
		node->cur = i;
		node->times = 0;
		node->valid = valid;
		node->pro = 1;
		for (int j = 0; j < 3; j++) {
			node->cmp[j] = cmp[j];
		}
		q.push(node);
	}
	bfs();
	cout << ans << '\n';
}