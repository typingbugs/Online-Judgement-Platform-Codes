#include<bits/stdc++.h>

using namespace std;
int ans;
vector<pair<int, int> > tree;

void dfs(int node, int d) {
    if (!tree[node].first && !tree[node].second) {
        ans = ans > d ? ans : d;
        return;
    }
    if (tree[node].first) {
        dfs(tree[node].first, d + 1);
    }
    if (tree[node].second) {
        dfs(tree[node].second, d + 1);
    }
}

int main() {
    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].first >> tree[i].second;
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}