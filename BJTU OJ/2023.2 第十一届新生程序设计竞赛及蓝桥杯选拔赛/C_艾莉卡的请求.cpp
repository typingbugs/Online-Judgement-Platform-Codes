#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<unsigned long long> a(n + 1), sum1(k + 1), sum2(k + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum1[0] = 0;
    sum2[0] = 0;
    for (int i = 1; i <= k; i++) sum1[i] = sum1[i - 1] + a[i];
    for (int i = 1; i <= k; i++) sum2[i] = sum2[i - 1] + a[n + 1 - i];
    unsigned long long ans = 0;
    for (int i = 0; i <= k; i++) {
        unsigned long long tmp = sum1[i] + sum2[k - i];
        ans = (tmp > ans ? tmp : ans);
    }
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}