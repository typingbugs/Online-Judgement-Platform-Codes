// Prim算法

#include <bits/stdc++.h>

using namespace std;
const int Z = 10005, N = 5001;
int ans;
int g[N][N];
int dis[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = Z;
        }
        dis[i] = Z;
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = z < g[x][y] ? z : g[x][y];
        g[y][x] = z < g[y][x] ? z : g[y][x];
    }
    int pos = 1;
    dis[pos] = 0;
    while (true) {
        for (int i = 1; i <= n; i++) {
            dis[i] = g[pos][i] < dis[i] ? g[pos][i] : dis[i];
        }
        int min = Z;
        int tmp = pos;
        for (int i = 1; i <= n; i++) {
            if (dis[i] != 0 && dis[i] < min) {
                pos = i;
                min = dis[i];
            }
        }
        if (pos != tmp) {
            ans += dis[pos];
            dis[pos] = 0;
        } else {
            for (int i = 1; i <= n; i++) {
                if (dis[i]) {
                    cout << "orz\n";
                    return 0;
                }
            }
            cout << ans << endl;
            return 0;
        }
    }
}
