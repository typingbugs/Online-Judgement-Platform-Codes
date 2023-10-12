#include<bits/stdc++.h>

using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int m = max(a, b), n = min(a, b);
    if (m == 1 && n == 1) printf("0\n");
    else if (n == 1) printf("%d\n", m);
    else printf("%d\n", 2 * (n - 1) + m);
}