# include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = -1000, s = a[0];
    ans = max(ans, s);
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 + 2) % 2 == (a[i - 1] % 2 + 2) % 2)
            s = a[i];
        else if (s < 0)
            s = a[i];
        else
            s += a[i];

        ans = max(ans, s);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}