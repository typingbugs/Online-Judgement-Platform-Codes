#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll num_x = n / x, num_y = n / y, num_xy = n / lcm(x, y);
    num_x -= num_xy;
    num_y -= num_xy;
    cout << (n + (n - num_x + 1)) * num_x / 2 - (1 + num_y) * num_y / 2 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}