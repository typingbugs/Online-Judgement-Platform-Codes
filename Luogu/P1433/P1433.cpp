#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
double ans = 10000.0;
double loc[16][2];
double dis[16][16];


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> loc[i][0] >> loc[i][1];
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dis[i][j] = sqrt(
                    (loc[i][0] - loc[j][0]) * (loc[i][0] - loc[j][0])
                    + (loc[i][1] - loc[j][1]) * (loc[i][1] - loc[j][1])
            );
            dis[j][i] = dis[i][j];
        }
    }

    printf("%.2lf\n", ans);
    return 0;
}
