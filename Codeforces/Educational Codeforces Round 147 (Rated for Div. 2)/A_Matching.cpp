#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s[0] == '0') {
        printf("0\n");
        return;
    }

    int cnt = 0;
    for (auto c: s) {
        if (c == '?') cnt++;
    }
    if (s[0] == '?') {
        cout << 9;
        cnt -= 1;
    } else cout << 1;
    while (cnt--) cout << 0;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}