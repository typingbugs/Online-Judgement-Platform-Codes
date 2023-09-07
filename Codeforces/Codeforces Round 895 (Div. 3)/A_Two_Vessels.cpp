#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << ceil(((a + b) / 2 - min(a, b)) / c) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
