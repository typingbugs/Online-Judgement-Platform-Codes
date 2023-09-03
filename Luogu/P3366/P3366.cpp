// Kruskal算法

#include<bits/stdc++.h>

using namespace std;
const int Z = 10005, N = 5001;
int n, m;
int ans;
vector<int> f(N);
vector<array<int, 3> > g;

bool cmp(array<int, 3> a, array<int, 3> b) {
    return a[2] < b[2];
}

int getf(int v) {
    return f[v] == v ? v : f[v] = getf(f[v]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 0; i < m; i++) {
        array<int, 3> edge;
        cin >> edge[0] >> edge[1] >> edge[2];
        if (edge[0] != edge[1]) {
            g.push_back(edge);
        }
    }

    sort(g.begin(), g.end(), cmp);
    int cnt = 0;
    for (auto iter: g) {
        int f1 = getf(iter[0]), f2 = getf(iter[1]);
        if (f1 != f2) {
            f[f2] = f1;
            ans += iter[2];
            if (++cnt == n - 1) {
                break;
            }
        }
    }
    if (cnt == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz\n";
    }
    return 0;
}