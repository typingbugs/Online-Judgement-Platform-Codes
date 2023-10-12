#include <bits/stdc++.h>

using namespace std;

bool g[8][8], d[7][7];
bool vis[8];
int visited;
int ans;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            d[i][j] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    while (visited < n) {
        int max = -1, pos_g = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int cnt = 0;
                for (int j = 1; j <= n; j++) {
                    if (g[i][j]) {
                        cnt++;
                    }
                }
                if (cnt > max) {
                    max = cnt;
                    pos_g = i;
                }
            }
        }
        vis[pos_g] = 1;
        visited++;
        int min = 7, pos_d = -1;
        for (int i = 1; i <= 6; i++) {
            int cnt = 0;
            for (int j = 1; j <= 6; j++) {
                if (d[i][j]) {
                    cnt++;
                }
            }
            if (cnt < min && cnt >= max) {
                min = cnt;
                pos_d = i;
            }
        }
        if (pos_d != -1) {
            for (int i = 1; min && i <= n; i++) {
                if (g[pos_g][i]) {
                    g[pos_g][i] = 0;
                    g[i][pos_g] = 0;
                    ans++;
                    min--;
                }
            }
            for (int i = 1; max && i <= 6; i++) {
                if (d[pos_d][i]) {
                    d[pos_d][i] = 0;
                    d[i][pos_d] = 0;
                    max--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}