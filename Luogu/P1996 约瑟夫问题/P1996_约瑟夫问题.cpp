#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int cnt = 1;
    while (!q.empty()) {
        int ans = q.front();
        q.pop();
        if (cnt % m == 0) {
            cout << ans << " ";
            cnt = 1;
        }
        else {
            q.push(ans);
        }
        cnt++;
    }
    return 0;
}