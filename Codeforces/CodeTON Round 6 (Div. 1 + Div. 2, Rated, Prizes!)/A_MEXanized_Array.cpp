# include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (n < k || k > x + 1) {
        cout << -1 << '\n';
        return;
    }
    int tmp = x != k ? x : x - 1;
    cout << (k - 1) * k / 2 + (n - k) * tmp << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}