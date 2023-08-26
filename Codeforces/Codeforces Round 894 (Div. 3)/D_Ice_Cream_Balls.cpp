#include<iostream>

using namespace std;
using ull = unsigned long long;

void solve() {
    ull input;
    cin >> input;
    ull l = 2, r = 1414213563;
    while (l < r) {
        ull mid = l + (r - l) / 2;
        if (mid * (mid - 1) / 2 <= input) l = mid + 1;
        else r = mid;
    }
    l--;
    cout << input - (l - 1) * l / 2 + l << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}