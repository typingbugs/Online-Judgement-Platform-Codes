#include <iostream>
#include <queue>

using namespace std;

int K[201];
bool vis[201];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == b) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> K[i];
    queue<int> q;
    vis[a] = true;
    q.push(a);
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int cnt = q.front() + 1;
        q.pop();
        int next[2] = {now - K[now], now + K[now]};
        for (auto i: next) {
            if (i == b) {
                cout << cnt << '\n';
                return 0;
            }
            if (i < 1 || i > n || vis[i]) continue;
            q.push(i);
            vis[i] = true;
            q.push(cnt);
        }
    }
    cout << "-1\n";
    return 0;
}
