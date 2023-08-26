# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> ans;
    ll input, tmp;
    cin >> input;
    ans.push_back(input);
    tmp = input;
    for (int i = 1; i < n; i++) {
        cin >> input;
        if (input >= tmp) ans.push_back(input);
        else {
            ans.push_back(input);
            ans.push_back(input);
        }
        tmp = input;
    }
    cout << ans.size() << '\n';
    for (auto i: ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}