#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > tree(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].first >> tree[i].second;
    }
    queue<pair<int, int> > bfs;
    bfs.push(pair<int, int>(1, 1));
    int ans = 0;
    while (!bfs.empty()) {
        pair<int, int> now = bfs.front();
        bfs.pop();
        ans = ans > now.second ? ans : now.second;
        if (tree[now.first].first) {
            bfs.push(pair<int, int>(tree[now.first].first, now.second + 1));
        }
        if (tree[now.first].second) {
            bfs.push(pair<int, int>(tree[now.first].second, now.second + 1));
        }
    }
    cout << ans << endl;
    return 0;
}