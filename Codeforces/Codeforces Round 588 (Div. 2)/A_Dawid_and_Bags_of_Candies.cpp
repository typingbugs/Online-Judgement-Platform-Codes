#include <bits/stdc++.h>

using namespace std;

int main() {
    int in[4];
    cin >> in[0] >> in[1] >> in[2] >> in[3];
    int sum = in[0] + in[1] + in[2] + in[3];
    for (int i = 1; i <= 14; i++) {
        int tmp = i;
        int add = 0;
        for (int j = 0; j < 4; j++) {
            if ((tmp >> j) & 1 == 1) {
                add += in[j];
            }
        }
        if (add == sum - add) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}