#include<bits/stdc++.h>
#include<array>

using namespace std;

typedef array<int, 4> AI4;

void solve();

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}

void solve() {
    map<string, AI4> m;
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            if (m.find(s) != m.end() && m[s][i] == 0) {
                m[s][i]++;
                m[s][3]++;
            } else {
                AI4 a = {0, 0, 0, 1};
                a[i] = 1;
                m[s] = a;
            }
        }
    }
    int ans[3] = {0};
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second[3] == 3) {
            continue;
        } else if (iter->second[3] == 1) {
            for (int i = 0; i < 3; i++) {
                if (iter->second[i] == 1) {
                    ans[i] += 3;
                    break;
                }
            }
        } else if (iter->second[3] == 2) {
            for (int i = 0; i < 3; i++) {
                if (iter->second[i] == 1)
                    ans[i] += 1;
            }
        }
    }
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}