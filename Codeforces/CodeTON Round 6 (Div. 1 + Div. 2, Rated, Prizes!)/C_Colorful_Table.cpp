# include<bits/stdc++.h>

using namespace std;

bool cmp_num(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool cmp_index(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> min_index(k + 1);
    vector<int> max_index(k + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (min_index[a] == 0) {
            min_index[a] = i;
            max_index[a] = i;
        }
        else max_index[a] = i;
    }
    int _min = 999999, _max = 0;
    for (int i = k; i > 0; i--) {
        if (min_index[i] != 0) {
            _min = min(_min, min_index[i]);
            min_index[i] = _min;
        }
        if (max_index[i] != 0) {
            _max = max(_max, max_index[i]);
            max_index[i] = _max;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (max_index[i] == 0) cout << 0 << ' ';
        else cout << 2 * (max_index[i] - min_index[i] + 1) << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}