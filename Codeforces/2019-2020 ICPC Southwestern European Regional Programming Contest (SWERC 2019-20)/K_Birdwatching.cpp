#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define N 100005

int n, m, t;
vector<vector<int> > edge(N);
queue<int> q;
unordered_map<int, int> cnt;
unordered_set<int> vis;

int main() {
	cin >> n >> m >> t;

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		edge[y].push_back(x);
	}
	vis.insert(t);
	for (int i = 0; i < edge[t].size(); i++) {
		cnt.insert(pair<int, int>(edge[t][i], 1));
		vis.insert(edge[t][i]);
		q.push(edge[t][i]);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < edge[now].size(); i++) {
			if (cnt.find(edge[now][i]) != cnt.end()) {
				cnt[edge[now][i]]++;
			}
			if (vis.insert(edge[now][i]).second) {
				q.push(edge[now][i]);
			}
		}
	}
	vector<int> ans;
	for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
		if (iter->second == 1) {
			ans.push_back(iter->first);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}