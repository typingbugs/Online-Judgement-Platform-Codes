#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool odd_n = (n % 2 == 1);
    int num_unpair = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) num_unpair++;
    }
    vector<int> ans;
    for (int i = 0; i < num_unpair; i++) ans.push_back(0);
    int append[2] = {1};
    append[1] = odd_n ? 1 : 0;
    for (int i = 0; i < n / 2 + 1 - num_unpair; i++) ans.push_back(append[i % 2]);
    for (auto i: ans) cout << i;
    if (!odd_n) ans.pop_back();
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}