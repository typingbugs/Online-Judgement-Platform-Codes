# include<bits/stdc++.h>

using namespace std;

int calculate(int a, int b, bool odd) {
    int w = 1, ans = 0;
    for (int i = 0; i < 31; i++) {
        int bit_a = a % 2;
        int bit_b = b % 2;
        if (bit_b == 1) {
            if (odd) ans += w;
        }
        else ans += bit_a * w;
        w *= 2;
        a /= 2;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        a ^= input;
    }
    for (int i = 0; i < m; i++) {
        cin >> input;
        b |= input;
    }
    int tmp = calculate(a, b, (n % 2 != 0));
    cout << min(a, tmp) << ' ' << max(a, tmp) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}