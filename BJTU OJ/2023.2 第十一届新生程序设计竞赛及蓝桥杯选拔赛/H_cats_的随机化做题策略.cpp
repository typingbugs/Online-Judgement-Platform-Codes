#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    while (n--) {
        double input;
        cin >> input;
        ans += (((double) 100) / input - 1.00) * 20.00;
    }
    cout << fixed << setprecision(7) << ans << '\n';
    return 0;
}