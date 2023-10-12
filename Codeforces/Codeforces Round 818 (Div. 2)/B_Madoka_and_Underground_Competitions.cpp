#include<bits/stdc++.h>

using namespace std;

void solve();

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    int first = r - c;
    for (int i = 0; i < n; i++) {
        int status = first - i;
        for (int j = 0; j < n; j++) {
            if ((j + status) % k == 0) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}