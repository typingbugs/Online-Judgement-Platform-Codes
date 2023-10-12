#include <iostream>

using namespace std;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    int tmp = a;
    string s;
    cin >> s;
    if (n == a) {
        cout << "YES" << '\n';
        return;
    }
    for (auto c: s) {
        if (c == '+') {
            a++;
            tmp++;
        } else a--;
        if (a == n) {
            cout << "YES" << '\n';
            return;
        }
    }
    if (tmp >= n) cout << "MAYBE" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}