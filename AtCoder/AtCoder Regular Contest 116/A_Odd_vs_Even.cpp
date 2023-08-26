#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long input;
        cin >> input;
        if (input % 2 == 1) {
            cout << "Odd\n";
            continue;
        }
        if (input == 2) {
            cout << "Same\n";
            continue;
        }
        int i = 0;
        bool find = 0;
        unsigned long long tmp;
        while (tmp = (input >> i)) {
            if ((tmp >> 1) && (tmp & 1)) {
                find = 1;
                break;
            }
            i++;
        }
        if (find) {
            if (i > 1) cout << "Even\n";
            else cout << "Same\n";
        } else cout << "Even\n";
    }
    return 0;
}