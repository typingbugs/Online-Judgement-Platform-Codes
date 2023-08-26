#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n, input, ans = 0;;
        scanf("%llu", &n);
        bool start = 0;
        for (int i = 1; i < n; i++) {
            scanf("%llu", &input);
            if (input == 0) {
                if (start)
                    ans++;
            } else {
                ans += input;
                start = 1;
            }
        }
        scanf("%llu", &input);
        printf("%llu\n", ans);
    }
}