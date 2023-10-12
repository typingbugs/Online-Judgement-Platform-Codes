#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string a, b;
    cin >> a;
    cin >> b;
    int n = a.length();
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '0')f[i] = 0;
            else f[i] = 1;
        } else f[i] = 2;
    }
    if (f[0] == 2 || f[n - 1] == 2) {
        cout << "NO\n";
        return;
    }
    if (f[0] == 0) {
        if (f[n - 1] == 0) {
            cout << "YES\n";
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            if (f[i] == 0 && f[i + 1] == 1) {
                cout << "YES\n";
                return;
            }
        }
    } else {
        if (f[n - 1] == 1) {
            cout << "YES\n";
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            if (f[i] == 1 && f[i + 1] == 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
