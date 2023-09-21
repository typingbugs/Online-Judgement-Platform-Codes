# include<bits/stdc++.h>

using namespace std;

#define ll long long

vector <pair<ll, ll> > fruit;
vector <ll> s;
ll k;

ll check(ll length) {
    ll volumn = 0;
    for (auto sub : fruit) {
        ll l = sub.first, r = sub.second, size = r - l;
        if (length > size) continue;
        for (int j = l; j < r - length + 1; j++) {
            if (s[j + length] - s[j] <= k) return true;
        }
    }
    return false;
}

void solve() {
    fruit.clear();
    ll n;
    cin >> n >> k;
    s.resize(n + 1);
    s[0] = 0;
    vector<ll> in_f(n), in_h(n);
    for (int i = 0; i < n; i++) {
        cin >> in_f[i];
        s[i + 1] = s[i] + in_f[i];
    }
    for (int i = 0; i < n; i++) cin >> in_h[i];
    ll l = 0, r = 1;
    ll last_h = in_h[0];
    for (int i = 1; i < n; i++) {
        if (last_h % in_h[i] == 0) {
            last_h = in_h[i];
        }
        else {
            fruit.push_back(pair<ll, ll>(l, r));
            l = i;
            last_h = in_h[i];
        }
        r = i + 1;
    }
    fruit.push_back(pair<ll, ll>(l, r));
    l = 1, r = 200005;
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