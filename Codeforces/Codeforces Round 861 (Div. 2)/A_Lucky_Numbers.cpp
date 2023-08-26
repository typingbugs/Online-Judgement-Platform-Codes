#include <bits/stdc++.h>

using namespace std;

pair<int, int> getmm(int num) {
    pair<int, int> ans;
    ans.first = 0;
    ans.second = 9;
    while (num) {
        ans.first = max(num % 10, ans.first);
        ans.second = min(num % 10, ans.second);
        num /= 10;
    }
    return ans;
}

int solve() {
    int l, r;
    cin >> l >> r;
    // l <= xx90 <= r
    int tmp = l % 100;
    if (90 - tmp >= 0 && 90 - tmp <= r - l) return l / 100 * 100 + 90;
    if (90 - tmp < 0 && r - l > 90 - tmp + 100) return (l + 100) / 100 * 100 + 90;
    int ans = l, dif = 0;
    for (int i = l; i <= r; i++) {
        pair<int, int> p = getmm(i);
        if (dif < p.first - p.second) {
            ans = i;
            dif = p.first - p.second;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
