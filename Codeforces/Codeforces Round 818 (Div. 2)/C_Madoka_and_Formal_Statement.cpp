#include<bits/stdc++.h>

using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    int len;
    cin >> len;
    vector<long long> a(len);
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }
    long long first, input, last;
    cin >> first;
    last = first;
    bool yes = 1;
    if (first < a[0]) {
        yes = 0;
    }
    for (int i = 1; i < len; i++) {
        cin >> input;
        if (yes) {
            if (input < a[i]) {
                yes = 0;
            } else if (last > a[i - 1] && input + 1 < last) {
                yes = 0;
            }
            last = input;
        }
    }
    if (a[len - 1] < input && first + 1 < input) {
        yes = 0;
    }

    if (yes) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}