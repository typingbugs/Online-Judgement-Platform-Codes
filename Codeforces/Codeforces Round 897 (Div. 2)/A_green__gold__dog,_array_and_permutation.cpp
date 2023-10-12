#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct {
    ll input;
    int order;
    int output;
} Num;

bool cmp1(Num a, Num b) {
    return a.input > b.input;
};

bool cmp2(Num a, Num b) {
    return a.order < b.order;
}

void solve() {
    int n;
    cin >> n;
    vector<Num> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].input;
        a[i].order = i + 1;
    }
    sort(a.begin(), a.end(), cmp1);
    for (int i = 0; i < n; i++) a[i].output = i + 1;
    sort(a.begin(), a.end(), cmp2);
    for (auto num: a) cout << num.output << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}