# include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n == 1) {
        cin >> n;
        cout << "NO" << endl;
        return;
    }
    long long a = 0, b = 0, tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > 1) a += tmp - 1;
        else b += 1;
    }
    if (a >= b) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
