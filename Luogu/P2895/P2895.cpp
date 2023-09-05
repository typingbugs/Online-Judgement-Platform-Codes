#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
bool vis[301][301];
bool destroyed[1001][301][301];


int main() {
    int m;
    cin >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        destroyed[c][a][b] = true;
        if (a + 1 <= 300) destroyed[c][a + 1][b] = true;
        if (a - 1 >= 0) destroyed[c][a - 1][b] = true;
        if (b + 1 <= 300) destroyed[c][a][b + 1] = true;
        if (b - 1 >= 0) destroyed[c][a][b - 1] = true;
    }
    if (destroyed[0][0][0]) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < 1000; i++)
        for (int x = 0; x < 301; x++)
            for (int y = 0; y < 301; y++)
                if (destroyed[i][x][y]) destroyed[i + 1][x][y] = true;
    if (!destroyed[1000][0][0]) {
        cout << "0\n";
        return 0;
    }
    queue<int> q;
    q.push(0);
    q.push(0);
    q.push(0);
    vis[0][0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        int t = q.front() + 1;
        q.pop();
        int next[8] = {x, y + 1, x, y - 1, x + 1, y, x - 1, y};
        for (int i = 0; i < 4; i++) {
            int next_x = next[i * 2], next_y = next[i * 2 + 1];
            if (next_x < 0 || next_y < 0) continue;
            if (next_x > 300 || next_y > 300) {
                cout << t << '\n';
                return 0;
            }
            if (!destroyed[1000][next_x][next_y]) {
                cout << t << '\n';
                return 0;
            }
            if (destroyed[t][next_x][next_y] || vis[next_x][next_y]) continue;
            q.push(next_x);
            q.push(next_y);
            q.push(t);
            vis[next_x][next_y] = true;
        }
    }
    cout << "-1\n";
    return 0;
}
