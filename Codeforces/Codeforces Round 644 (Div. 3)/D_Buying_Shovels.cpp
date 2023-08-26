#include<bits/stdc++.h>

using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) solve();
    return 0;
}

set<int> a;

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.insert(i);
            a.insert(n / i);
        }
    }
    auto i = a.end();
    i--;
    bool f = 0;
    for (; i != a.begin(); i--) {
        if (*i <= k) {
            f = 1;
            break;
        }
    }
    if (f) printf("%d\n", n / (*i));
    else printf("%d\n", n);
    a.clear();
}