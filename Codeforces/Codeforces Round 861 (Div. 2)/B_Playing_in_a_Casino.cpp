#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

u64 solve() {
    u64 n, m;
    cin >> n >> m;
    vector<vector<u64> > a(m);
    for (int i = 0; i < m; i++) a[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[j][i];
    }
    u64 ans = 0;
    for (int i = 0; i < m; i++) {
        sort(a[i].begin(), a[i].end());
        for (u64 j = 1; j < n; j++) ans += j * (n - j) * (a[i][j] - a[i][j - 1]);
    }
    return ans;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}