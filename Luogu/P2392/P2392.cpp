#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int solve(int n) {
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int min = 1500, ans = 0;
    for (ll state = 1; state < (1 << n); state++) {
        ll tmp = state;
        int sum_l = 0, sum_r = 0;
        for (int i = 0; i < n; i++) {
            if ((tmp >> i) & (ll) 1) sum_l += s[i];
            else sum_r += s[i];
        }
        if (abs(sum_r - sum_l) <= min) {
            ans = max(sum_l, sum_r);
            min = abs(sum_r - sum_l);
        }
    }
    return ans;
}

int main() {
    vector<int> s(4);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    int sum = 0;
    for (int i: s) sum += solve(i);
    cout << sum << '\n';
    return 0;
}
