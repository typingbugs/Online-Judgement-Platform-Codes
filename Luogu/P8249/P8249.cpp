#include<bits/stdc++.h>

using namespace std;

int a, b, q;

vector<int> mod_sum;

void solve() {
    int l, r;
    cin >> l >> r;
}

int main() {
    cin >> a >> b >> q;
    for (int i = 0; i < a / __gcd(a, b) * b; i++) mod_sum.push_back(i % a + i % b);
    while (q--) solve();
    return 0;
}