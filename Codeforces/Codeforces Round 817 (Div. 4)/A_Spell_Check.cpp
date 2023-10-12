#include<bits/stdc++.h>

using namespace std;

void solve();

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        solve();
    }
}

void solve() {
    bool rec[5] = {0};
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char in = getchar();
        if (in == 'T') {
            rec[0] = 1;
        } else if (in == 'i') {
            rec[1] = 1;
        } else if (in == 'm') {
            rec[2] = 1;
        } else if (in == 'u') {
            rec[3] = 1;
        } else if (in == 'r') {
            rec[4] = 1;
        }
    }
    getchar();
    bool ans = 1;
    for (int i = 0; i < 5; i++) {
        if (rec[i] != 1) {
            ans = 0;
            break;
        }
    }
    if (ans && n == 5) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}