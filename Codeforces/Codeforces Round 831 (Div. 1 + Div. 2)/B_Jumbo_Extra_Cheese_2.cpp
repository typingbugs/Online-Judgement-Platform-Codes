#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        ull ans = 0;
        int n = 0;
        cin >> n;
        int Max = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            int M = max(a, b);
            Max = M > Max ? M : Max;
            ans += 2 * min(a, b);
        }
        ans += 2 * Max;
        cout << ans << endl;
    }
    return 0;
}