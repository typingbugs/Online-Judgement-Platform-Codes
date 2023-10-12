#include<bits/stdc++.h>

using namespace std;

using U64 = unsigned long long;

void solve();

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}

void solve() {
    U64 n;
    cin >> n;
    char L[200005];
    cin >> L;
    U64 ans = 0, max = 0;
    for (U64 i = 0; i < n / 2; i++) {
        if (L[i] == 'R') {
            ans += n - 1 - i;
        } else {
            ans += i;
            max++;
        }
        if (L[n - 1 - i] == 'L') {
            ans += n - 1 - i;
        } else {
            ans += i;
            max++;
        }
    }
    if (n % 2 == 1) {
        ans += n / 2;
    }
    U64 cnt = max;
    for (U64 i = 0; i < n / 2; i++) {
        if (L[i] == 'L') {
            ans += n - 1 - 2 * i;
            printf("%llu ", ans);
            cnt--;
        }
        if (L[n - 1 - i] == 'R') {
            ans += n - 1 - 2 * i;
            printf("%llu ", ans);
            cnt--;
        }
        if (cnt == 0) {
            break;
        }
    }
    for (U64 i = n - max; i > 0; i--) {
        printf("%llu ", ans);
    }
    printf("\n");
}