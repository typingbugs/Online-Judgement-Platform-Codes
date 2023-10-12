#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        long long ans = num[n - 1] - num[0];
        for (int i = 1; i < n; i++) {
            ans = max({ans, (long long) 2 * num[i] - num[i - 1] - num[0],
                       (long long) num[n - 1] + num[i] - 2 * num[i - 1]});
        }
        cout << ans << endl;
    }
    return 0;
}