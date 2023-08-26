#include<bits/stdc++.h>

using namespace std;
long arm[20];

int main() {
    long m;
    int n;
    long count = 0;
    scanf("%d%ld", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%ld", &arm[i]);
    int s;
    for (s = 1; s < (1 << n); s++) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            if (((s >> i) & 1) == 1)
                sum += arm[i];
        }
        if (sum == m)
            count++;
    }
    printf("%ld\n", count);
    return 0;
}