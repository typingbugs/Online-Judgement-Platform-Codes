#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        bool flag = 1;
        cin >> a >> b >> c >> d;
        if (a < d && c < b) flag = 0;
        if (c < b && a < d)flag = 0;
        if (!flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}