#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > ds(n);
    for (int i = 0; i < n; i++) cin >> ds[i].first >> ds[i].second;
    int ans = 300;
    for (auto a: ds) {
        int d = a.first, s = a.second;
        ans = min(ans, d + (s - 1) / 2);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}