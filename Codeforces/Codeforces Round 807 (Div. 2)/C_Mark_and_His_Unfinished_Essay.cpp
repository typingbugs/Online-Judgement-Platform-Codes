#include<bits/stdc++.h>

using namespace std;

char ss[200002];
long long index1[100];
long long index2[100];

int main() {
    ss[0] = '0';
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c, q;
        scanf("%d %d %d", &n, &c, &q);
        scanf("%s", ss + 1);
        int prsnt = 0;
        long long len = n, l, r;
        for (int i = 0; i < c; i++) {
            scanf("%lld %lld", &l, &r);
            index1[++prsnt] = len + 1;
            index2[prsnt] = l;
            index1[++prsnt] = (len = len + 1 - l + r);
            index2[prsnt] = r;
        }
        while (q--) {
            long long qst;
            scanf("%lld", &qst);
            while (qst > n) {
                long long pos = lower_bound(index1 + 1, index1 + prsnt + 1, qst) - index1;
                qst = index2[pos] - index1[pos] + qst;
            }
            printf("%c\n", ss[qst]);
        }
    }
}