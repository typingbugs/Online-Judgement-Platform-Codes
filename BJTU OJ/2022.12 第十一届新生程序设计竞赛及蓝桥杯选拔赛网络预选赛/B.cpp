#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > mx(200);
vector<bool> vis(200);

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx[a[i] % m].push_back(a[i]);
        vis[a[i] % m] = true;
    }
    for (int i = 0; i < 200; i++) {
        if (vis[i]) {
            sort(mx[i].begin(), mx[i].end(), cmp);
        }
    }
    int cnt[200] = {0};
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        sum += mx[a[i] % m][cnt[a[i] % m]++];
    }
    ans = max(ans, sum);
    for (int i = 1; i < n - k + 1; i++) {
        sum -= mx[a[i - 1] % m][--cnt[a[i - 1] % m]];
        sum += mx[a[i + k - 1] % m][cnt[a[i + k - 1] % m]++];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}