#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    map<PII, int> input;
    for (int iter = 0; iter < q; iter++) {
        int a, i, j;
        cin >> a;
        if (a == 1) {
            int k;
            cin >> i >> j >> k;
            input[PII(i, j)] = k;
        }
        else {
            cin >> i >> j;
            cout << input[PII(i, j)] << '\n';
        }
    }
    return 0;
}