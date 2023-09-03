#include <bits/stdc++.h>

using namespace std;
vector<bool> vis(1002);

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> q(m);
    int ans = 0;
    while (n--) {
        int a;
        cin >> a;
        a++;
        if (!vis[a]) {
            vis[q[ans % m]] = false;
            q[ans % m] = a;
            vis[a] = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
