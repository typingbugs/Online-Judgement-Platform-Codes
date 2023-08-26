//正解，二维数组前缀和
#include<bits/stdc++.h>

using namespace std;

#define N 1000
using I64 = long long;

void solve();

I64 qw[N + 1][N + 1], ans[N + 1][N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            qw[i][j] = 0;
            ans[i][j] = 0;
        }
    }
    I64 n, q;
    cin >> n >> q;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        qw[a][b] += a * b;
    }
    ans[1][1] = qw[1][1];
    for (int i = 2; i <= N; i++) {
        ans[1][i] = ans[1][i - 1] + qw[1][i];
        ans[i][1] = ans[i - 1][1] + qw[i][1];
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            ans[i][j] = qw[i][j] + ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
        }
    }
    int x1, y1, x2, y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        printf("%lld\n", ans[x2 - 1][y2 - 1] - ans[x2 - 1][y1] - ans[x1][y2 - 1] + ans[x1][y1]);
    }
}

//暴力解法，TLE on test 8
//#include<bits/stdc++.h>
//using namespace std;
//
//using I64 = long long;
//using PII = pair<int, int>;
//
//void solve();
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}
//
//void solve() {
//    I64 n, q;
//    cin >> n >> q;
//    vector<PII> rtg(n);
//    for (int i = 0; i < n; i++) {
//        cin >> rtg[i].first >> rtg[i].second;
//    }
//    sort(rtg.begin(), rtg.end());
//    I64 que[4];
//    for (int i = 0; i < q; i++) {
//        cin >> que[0] >> que[1] >> que[2] >> que[3];
//        I64 ans = 0;
//        auto pos = upper_bound(rtg.begin(), rtg.end(), PII(que[0], que[1]));
//        for (; pos != rtg.end() && pos->first == que[0]; pos++) {
//        }
//        for (; pos != rtg.end() && pos->first < que[2]; pos++) {
//            if (pos->second > que[1] && pos->second < que[3]) {
//                ans += (I64)pos->first * pos->second;
//            }
//        }
//        printf("%lld\n", ans);
//    }
//}