#include <iostream>

using namespace std;
using i64 = long long;

void solve() {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < b) {
        cout << -1 << '\n';
        return;
    }
    if (c - a > d - b) {
        cout << -1 << '\n';
        return;
    }
    cout << 2 * (d - b) + a - c << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
