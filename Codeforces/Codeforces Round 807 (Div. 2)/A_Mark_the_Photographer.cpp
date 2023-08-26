#include<bits/stdc++.h>

using namespace std;

int psn[500];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d %d", &psn[0], &x);
        for (int i = 1; i <= 2 * psn[0]; i++) {
            scanf("%d", &psn[i]);
        }
        sort(psn + 1, psn + 2 * psn[0] + 1);
        bool flag = 1;
        for (int i = psn[0]; i >= 1; i--) {
            if (psn[i + psn[0]] - psn[i] < x) {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}