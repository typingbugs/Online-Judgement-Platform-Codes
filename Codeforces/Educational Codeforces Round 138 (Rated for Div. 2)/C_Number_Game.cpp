#include<bits/stdc++.h>

using namespace std;
vector<int> arr;

bool check(int k) {
    bool flag = true;
    for (int i = 1; i <= k; i++) {
        if (arr[2 * k - 1 - i] > k - i + 1) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int l = 1, r = (n + 1) / 2 + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << l - 1 << endl;
    }
    return 0;
}