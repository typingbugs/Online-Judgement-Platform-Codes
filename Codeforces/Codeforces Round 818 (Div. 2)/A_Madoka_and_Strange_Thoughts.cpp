#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned long long n;
        cin >> n;
        printf("%llu\n", n + n / 2 * 2 + n / 3 * 2);
    }
    return 0;
}