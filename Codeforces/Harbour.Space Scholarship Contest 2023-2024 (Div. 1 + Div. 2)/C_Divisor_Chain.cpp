#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 73 = 2^0 + 72                -> 73 - 2^0 = 72
//    = 2^0 + 2*36
//    = 2^0 + 2*2*18
//    = 2^0 + 2*2*2*9
//    = 2^0 + 2^3 + 2*2*2*8     -> 72 - 2^3 = 64
//    = 2^0 + 2^3 + 2*2*2*2*2*2 -> 64 - 32 - 16 - 8 - 4 - 2 - 1 = 1
// Any power of 2 appears no more than twice.

void solve() {
    vector<ll> ans;
    ll x;
    cin >> x;
    ans.push_back(x);
    ll t = 1;
    ll last = x;
    while (last != 2) {
        if (last % 2) {
            x -= t;
            ans.push_back(x);
            last -= 1;
        } else {
            t *= 2;
            last /= 2;
        }
    }
    while (t != 0) {
        ans.push_back(t);
        t /= 2;
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