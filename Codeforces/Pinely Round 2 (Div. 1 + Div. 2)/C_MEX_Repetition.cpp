#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> f;

void solve() {
    int n, k;
    cin >> n >> k;
    f.resize(n + 1);
    for (int i = 0; i <= n; i++) f[i] = false;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (!f[i]) {
            a[n] = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) cout << a[((-k + i) % (n + 1) + (n + 1)) % (n + 1)] << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}