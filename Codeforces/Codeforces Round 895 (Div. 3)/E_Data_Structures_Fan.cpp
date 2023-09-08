#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int XOR_all = 0, XOR_1 = 0;
    vector<int> a(n + 1);
    vector<int> record(n + 1);
    record[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        XOR_all ^= a[i];
        record[i] = record[i - 1] ^ a[i];
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) XOR_1 = (s[i - 1] == '1') ? XOR_1 ^ a[i] : XOR_1;
    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            XOR_1 ^= record[r] ^ record[l - 1];
        } else {
            int g;
            cin >> g;
            if (g == 0) cout << (XOR_all ^ XOR_1) << ' ';
            else cout << XOR_1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}