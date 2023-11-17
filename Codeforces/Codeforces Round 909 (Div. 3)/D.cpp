# include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, long long> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
    }
    unsigned long long ans = m[1] * m[2];
    for (auto iter = m.begin(); iter != m.end(); iter++) ans += (iter->second - 1) * iter->second / 2;
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}