#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> A;
int ans = 1;

int main() {
    A.push_back(1);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > cnt(m + 1);
    vector<int> ts(m + 1);
    vector<bool> vis(m + 1);
    for (int i = 1; i <= m; i++) {
        cnt[i].resize(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        int in;
        while (len--) {
            cin >> in;
            cnt[in][i]++;
            ts[in]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        int sameNum = 1;
        vis[i] = 1;
        for (int j = i + 1; j <= m; j++) {
            if (!vis[j] && ts[i] == ts[j]) {
                bool ok = 1;
                for (int k = 1; k <= n; k++) {
                    if (cnt[i][k] != cnt[j][k]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    sameNum++;
                    vis[j] = 1;
                }
            }
        }
        while (A.size() < sameNum + 1) {
            A.push_back((int) (((ll) A.back() * (A.size() + 1)) % 1000000007));
        }
        ans = (ans * A[sameNum - 1]) % 1000000007;
    }
    cout << ans << '\n';
    return 0;
}
