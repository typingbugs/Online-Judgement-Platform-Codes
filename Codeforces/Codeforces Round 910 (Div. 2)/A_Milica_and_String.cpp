# include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt_a = 0, cnt_b = 0;
    for (auto c : s) {
        if (c == 'A') cnt_a++;
        else cnt_b++;
    }
    if (cnt_b == k) {
        cout << 0 << '\n';
    }
    else if (cnt_b > k) {
        cout << 1 << '\n';
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            if (s[i] == 'B') cnt++;
            if (cnt == cnt_b - k) {
                cout << i + 1 << " A\n";
                return;
            }
        }
    }
    else {
        cout << 1 << '\n';
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            if (s[i] == 'A') cnt++;
            if (cnt == k - cnt_b) {
                cout << i + 1 << " B\n";
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}