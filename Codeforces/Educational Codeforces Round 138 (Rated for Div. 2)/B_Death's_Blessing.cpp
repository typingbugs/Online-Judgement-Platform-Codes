#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> hp(n), sk(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> hp[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> sk[i];
            if (sk[i] == 0) {
                ans += hp[i];
            }
        }
        int l = 0, r = n - 1;
        long long l_sk = 0, r_sk = 0;
        while (sk[l] == 0) {
            l++;
        }
        while (sk[r] == 0) {
            r--;
        }
        while (l < r) {
            if (sk[l] <= sk[r]) {
                ans += hp[l] + l_sk;
                l_sk = sk[l];
                l++;
                while (l < r && sk[l] == 0) {
                    l++;
                }
            } else {
                ans += hp[r] + r_sk;
                r_sk = sk[r];
                r--;
                while (r > l && sk[r] == 0) {
                    r--;
                }
            }
        }
        if (l == r && sk[l] != 0) {
            ans += hp[l] + l_sk + r_sk;
        }
        cout << ans << endl;
    }
    return 0;
}