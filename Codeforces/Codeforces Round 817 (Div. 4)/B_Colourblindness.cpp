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
    int n;
    scanf("%d", &n);
    getchar();
    char first[101];
    scanf("%s", first);
    getchar();
    bool ans = 1;
    char in;
    for (int i = 0; i < n; i++) {
        if (!((in = getchar()) == first[i] ||
              (in == 'G' && first[i] == 'B') ||
              (in == 'B' && first[i] == 'G'))) {
            ans = 0;
        }
    }
    getchar();
    if (ans) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
