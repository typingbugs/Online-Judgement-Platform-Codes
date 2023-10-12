#include<bits/stdc++.h>

using namespace std;

bool grid[100][100];

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) {
        int n;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = getchar() - '0';
            }
            getchar();
        }
        int ans = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int cnt = 0;
                if (grid[i][j] == 0)cnt++;
                if (grid[n - 1 - j][i] == 0)cnt++;
                if (grid[n - 1 - i][n - 1 - j] == 0)cnt++;
                if (grid[j][n - 1 - i] == 0)cnt++;
                ans += cnt < (4 - cnt) ? cnt : (4 - cnt);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}