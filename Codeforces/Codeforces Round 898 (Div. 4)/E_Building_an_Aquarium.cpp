# include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> coral;
ll x;

bool check(ll h) {
    ll volumn = 0;
    for (auto i : coral) volumn += max((ll)0, h - i);
    if (volumn > x) return false;
    else return true;
}

void solve() {
    ll n;
    cin >> n >> x;
    coral.resize(n);
    for (int i = 0; i < n; i++) cin >> coral[i];
    ll l = 1, r = 2000000005;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (!check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}