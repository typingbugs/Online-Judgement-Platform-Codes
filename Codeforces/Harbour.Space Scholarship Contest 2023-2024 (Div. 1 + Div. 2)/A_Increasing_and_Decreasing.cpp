#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> out(n);
    out[0] = y;
    for (int i = 1; i < n; i++) {
        out[i] = out[i - 1] - i;
    }
    if (x > out[n - 1]) {
        cout << -1 << '\n';
        return;
    }
    out[n - 1] = x;
    for (int i = n - 1; i >= 0; i--) cout << out[i] << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
