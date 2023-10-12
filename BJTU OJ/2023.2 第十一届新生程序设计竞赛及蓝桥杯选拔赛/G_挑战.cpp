#include <bits/stdc++.h>

using namespace std;
using u_64 = unsigned long long;

u_64 n, m;
vector<u_64> a(100005), b(100005);

int check(u_64 ans) {
    u_64 sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans / b[i] * a[i] + min(ans % b[i], a[i]);
        if (sum > m) return -1;
    }
    if (sum < m) return 1;
    else return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] += a[i];
    }
    u_64 l = 1, r = 10000000000000, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        int ans = check(mid);
        if (ans == 0) break;
        if (ans > 0) l = mid + 1;
        else r = mid - 1;
    }
    cout << mid << '\n';
    return 0;
}