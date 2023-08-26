#include <iostream>

using namespace std;

int solve() {
    int len;
    cin >> len;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, a;
    for (int i = 0; i < len; i++) {
        cin >> a;
        if (a == 0) cnt0++;
        if (a == 1) cnt1++;
        if (a > 1) cnt2++;
    }
    if (cnt0 <= 1) return 0; // no 0
    if (cnt1 == 0) { // no 1
        if (cnt2 >= cnt0 - 1) return 0;
        else return 1;
    }
    if (cnt2 == 0) { // no >1
        if (cnt1 >= cnt0 - 1) return 0;
        else return 2;
    }
    if (cnt1 + cnt2 >= cnt0 - 1) return 0;
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}