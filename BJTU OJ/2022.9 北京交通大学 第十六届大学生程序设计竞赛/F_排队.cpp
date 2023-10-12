#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), d(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (a[0] == b[0]) {
        d[0] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i]) {
            d[i] = d[i - 1] + 1;
        } else {
            d[i] = d[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] == b[i]) {
            e[i] = e[i + 1] + 1;
        } else {
            e[i] = e[i + 1];
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        int tmp = e[i] + d[i];
        if (a[i] == b[i]) {
            tmp--;
        }
        if (a[i] == b[n - 1]) {
            tmp++;
        }
        max = max < tmp ? tmp : max;
    }
    cout << max << '\n';
}