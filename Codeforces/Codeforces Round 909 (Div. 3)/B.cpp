# include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<ull> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
    }
    ull ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        int k = n / i;

        ull _min = 1e16, _max = 0;
        for (int j = 1; j <= k; j++) {
            ull s = b[j * i] - b[(j - 1) * i];
            _min = min(_min, s);
            _max = max(_max, s);
        }
        ans = max(ans, _max - _min);


        _min = 1e16;
        _max = 0;
        for (int j = 1; j <= i; j++) {
            ull s = b[j * k] - b[(j - 1) * k];
            _min = min(_min, s);
            _max = max(_max, s);
        }
        ans = max(ans, _max - _min);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}