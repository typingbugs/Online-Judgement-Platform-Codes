#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m > n) {
            for (int i = 0; i < m; i++) {
                int x, y;
                cin >> x >> y;
            }
            cout << "NO" << endl;
            continue;
        }
        vector<int> cntR(n + 1), cntC(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            cntR[x]++;
            cntC[y]++;
        }
        bool flag1 = false, flag2 = false;
        int cntX = 0, cntY = 0;
        for (int i = 1; i <= n; i++) {
            if (cntR[i]) { cntX += cntR[i] - 1; }
            else {
                flag1 = true;
            }
        }
        if (cntX > 1) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (cntC[i]) { cntY += cntC[i] - 1; }
            else {
                flag2 = true;
            }
        }
        if (cntY > 1) {
            cout << "NO" << endl;
            continue;
        }
        if (!flag1 && !flag2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}