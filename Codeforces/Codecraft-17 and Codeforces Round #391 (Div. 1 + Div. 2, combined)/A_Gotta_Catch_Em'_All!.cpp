#include <bits/stdc++.h>

using namespace std;

int cnt[7];

int main() {
    string in;
    cin >> in;
    for (auto x: in) {
        if (x == 'B') {
            cnt[0]++;
        } else if (x == 'u') {
            cnt[1]++;
        } else if (x == 'l') {
            cnt[2]++;
        } else if (x == 'b') {
            cnt[3]++;
        } else if (x == 'a') {
            cnt[4]++;
        } else if (x == 's') {
            cnt[5]++;
        } else if (x == 'r') {
            cnt[6]++;
        }
    }
    cnt[1] /= 2;
    cnt[4] /= 2;
    int ans = 1E9;
    for (int i = 0; i < 7; i++) {
        ans = (cnt[i] < ans) ? cnt[i] : ans;
    }
    cout << ans << endl;
    return 0;
}

