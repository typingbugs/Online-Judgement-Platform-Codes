#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll last;
    cin >> last;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<int> ans;
    ans.push_back(0);
    int zheng = 1, fu = -1;
    for (int i = 0; i < n - 1; i++) {
        ll now;
        cin >> now;
        ll dif = now - last;
        if (dif > 0) {
            ans.push_back(fu);
            fu--;
        } else {
            ans.push_back(zheng);
            zheng++;
        }
    }
    for (int i: ans) cout << i - fu << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}