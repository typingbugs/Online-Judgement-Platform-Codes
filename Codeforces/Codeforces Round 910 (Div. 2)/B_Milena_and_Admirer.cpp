# include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0 ;i < n; i++) cin >> a[i];
    long long m = a[n - 1], ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= m) {
            m = a[i];
        } else {
            long long inc = (a[i] - 1) / m;
            ans += inc;
            m = a[i] / (inc + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}