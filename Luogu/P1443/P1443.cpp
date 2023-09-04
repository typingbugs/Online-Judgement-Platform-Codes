#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll board[401][401];

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[i][j] = -1;
        }
    }
    board[x][y] = 0;
    queue<pii> q;
    pii p0(x, y);
    q.push(p0);
    while (!q.empty()) {
        pair<int, int> now = q.front();
        int x1 = now.first, y1 = now.second;
        ll dis = board[x1][y1];
        q.pop();
        int next[16] = {x1 + 2, y1 + 1, x1 + 2, y1 - 1, x1 + 1, y1 + 2, x1 + 1, y1 - 2,
                        x1 - 1, y1 + 2, x1 - 1, y1 - 2, x1 - 2, y1 + 1, x1 - 2, y1 - 1};
        for (int i = 0; i < 8; i++) {
            int x2 = next[i * 2], y2 = next[i * 2 + 1];
            if (x2 < 0 || x2 > n || y2 < 0 || y2 > m) continue;
            if (board[x2][y2] != -1) continue;
            board[x2][y2] = dis + 1;
            pii p1(x2, y2);
            q.push(p1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
