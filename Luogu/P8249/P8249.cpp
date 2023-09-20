#include <bits/stdc++.h>

using namespace std;

int a, b, q;
int period;

vector<int> mod_sum;

void solve() {
    int l, r;
    cin >> l >> r;
    int l_loop = l / period, r_loop = r / period;
    if (l_loop != r_loop) {
        cout << a + b - 2 << '\n';
        return;
    }
    l %= period;
    r %= period;
    vector<int> ans;
    ans.push_back(mod_sum[l]);
    ans.push_back(mod_sum[r]);
    if (r / a * a - 1 > l) ans.push_back(mod_sum[r / a * a - 1]);
    if (r / b * b - 1 > l) ans.push_back(mod_sum[r / b * b - 1]);
    int _max = -1;
    for (auto i : ans) _max = max(_max, i);
    cout << _max << '\n';
}

int main() {
    cin >> a >> b >> q;
    period = a / __gcd(a, b) * b;
    for (int i = 0; i < period; i++)
        mod_sum.push_back(i % a + i % b);
    while (q--)
        solve();
    return 0;
}