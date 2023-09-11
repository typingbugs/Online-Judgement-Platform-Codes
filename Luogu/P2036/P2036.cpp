#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll sb[11][2];
int n;
ll ans = 1e10;

void dfs(int index, ll s, ll b, bool chose) {
    if (index == n) {
        if (chose) ans = ans < abs(s - b) ? ans : abs(s - b);
        return;
    }
    dfs(index + 1, s * sb[index][0], b + sb[index][1], true);
    dfs(index + 1, s, b, chose);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> sb[i][0] >> sb[i][1];
    dfs(0, 1, 0, false);
    cout << ans << '\n';
    return 0;
}


