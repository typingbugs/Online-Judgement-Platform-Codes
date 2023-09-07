#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll l, r;
    cin >> l >> r;
    if (r < 4) {
        cout << -1 << '\n';
        return;
    }
    for (ll i = r; i >= l; i--) {
        if (i % 2 == 0) {
            cout << 2 << ' ' << i - 2 << '\n';
            return;
        }
    }
    ll a = -1;
    for (ll i = 3; i * i <= l; i++) {
        if (l % i == 0) {
            a = i;
            break;
        }
    }
    if (a == -1) cout << -1 << '\n';
    else cout << a << ' ' << l - a << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}