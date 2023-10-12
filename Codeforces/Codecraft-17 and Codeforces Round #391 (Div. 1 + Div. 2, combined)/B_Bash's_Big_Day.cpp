#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> pkm;
    int in;
    for (int i = 0; i < t; i++) {
        cin >> in;
        if (in == 1) {
            continue;
        }
        pkm.push_back(in);
    }
    vector<int> ans(pkm.size());
    sort(pkm.begin(), pkm.end());
    for (int i = 0; i < pkm.size(); i++) {
        int m = 0, pos = i;
        for (int j = 0; j <= i; j++) {
            if (pkm[i] % pkm[j] == 0) {
                if (ans[j] > m) {
                    m = ans[j];
                    pos = j;
                }
            }
        }
        ans[pos]++;
    }
    int max = 0;
    for (auto x: ans) {
        max = (max >= x) ? max : x;
    }
    cout << max << '\n';
    return 0;
}