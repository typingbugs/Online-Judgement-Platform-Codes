#include<bits/stdc++.h>

using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    long long n, k, b, s;
    cin >> n >> k >> b >> s;
    if (n * (k - 1) + b * k < s || b * k > s) {
        printf("-1\n");
    } else {
        printf("%lld ", min(((b + 1) * k - 1), s));
        s -= (b + 1) * k - 1;
        for (int i = 0; i < n - 1; i++) {
            if (s <= 0) {
                printf("0 ");
            } else {
                printf("%d ", min(k - 1, s));
                s -= k - 1;
            }
        }
        printf("\n");
    }
}