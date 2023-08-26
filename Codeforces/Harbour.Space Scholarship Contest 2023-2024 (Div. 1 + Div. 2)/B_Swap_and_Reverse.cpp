#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    if (k % 2) {
        vector<char> odd, even;
        for (int i = 0; i < n; i++) {
            if (i % 2) odd.push_back(s[i]);
            else even.push_back(s[i]);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        for (int i = 0; i < n / 2; i++) cout << even[i] << odd[i];
        if (n % 2) cout << even[n / 2];
    } else {
        vector<char> ans(n);
        for (int i = 0; i < n; i++) ans[i] = s[i];
        sort(ans.begin(), ans.end());
        for (auto i: ans) cout << i;
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}