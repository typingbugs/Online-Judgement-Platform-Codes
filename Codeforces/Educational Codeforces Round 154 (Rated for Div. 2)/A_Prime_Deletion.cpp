#include <iostream>

using namespace std;

void solve() {
    string s;
    cin >> s;
    for (auto c: s) {
        if (c == '3') {
            cout << "31" << '\n';
            return;
        } else if (c == '1') {
            cout << "13" << '\n';
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
