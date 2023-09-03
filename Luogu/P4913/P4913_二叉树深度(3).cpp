#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > tree(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].first >> tree[i].second;
    }
    vector<pair<bool, bool> > vis(n + 1);
    stack<int> dfs;
    dfs.push(1);
    int m = 0;
    int d = 1;
    while (!dfs.empty()) {
        int node = dfs.top();
        m = m > d ? m : d;
        if (!vis[node].first && tree[node].first) {
            vis[node].first = true;
            dfs.push(tree[node].first);
            d++;
        } else if (!vis[node].second && tree[node].second) {
            vis[node].second = true;
            dfs.push(tree[node].second);
            d++;
        } else {
            dfs.pop();
            d--;
        }
    }
    cout << m << endl;
    return 0;
}
