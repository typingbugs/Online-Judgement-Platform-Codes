# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

void solve() {
    long long m, k, a_1, a_k;
    cin >> m >> k >> a_1 >> a_k;
    long long coin_k = m / k;
    long long coin_1 = m % k;
    long long fancy_1 = coin_1 - min(coin_1, a_1);
    a_1 -= min(coin_1, a_1);
    long long fancy_k = coin_k - min(coin_k, a_k);
    fancy_k -= min(fancy_k, a_1 / k);
    cout << fancy_1 + fancy_k << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}