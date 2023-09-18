# include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

ll calculate(ll a, ll b, bool odd) {
    ll w = 1, ans = 0;
    for (int i = 0; i < sizeof(ll); i++) {
        ll bit_a = (a >> i) & 1;
        ll bit_b = (b >> i) & 1;
        if (bit_b == 1) {
            if (odd) ans += w;
        }
        else ans += bit_a * w;
        w *= 2;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll a = 0, b = 0;
    ll input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        a ^= input;
    }
    for (int i = 0; i < m; i++) {
        cin >> input;
        b |= input;
    }
    ll tmp = calculate(a, b, (n % 2 != 0));
    cout << min(a, tmp) << ' ' << max(a, tmp) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}