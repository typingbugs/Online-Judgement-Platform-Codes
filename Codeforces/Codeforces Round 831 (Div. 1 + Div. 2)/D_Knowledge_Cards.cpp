#include<bits/stdc++.h>

using namespace std;

void solve() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<bool> in_plc(k + 1);
    int plc = (m - 1) * (n - 1);
    int tar = k;
    while (k--) {
        int a;
        cin >> a;
        if (a == tar) {
            tar--;
        } else {
            in_plc[a] = 1;
            plc--;
            if (plc < 0) {
                cout << "TIDAK" << endl;
                while (k--) {
                    cin >> a;
                }
                return;
            }
        }
        while (tar != 0 && in_plc[tar]) {
            tar--;
        }
        if (tar == 0) {
            cout << "YA" << endl;
            while (k--) {
                cin >> a;
            }
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}