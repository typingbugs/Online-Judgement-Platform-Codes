#include<bits/stdc++.h>
#include<array>

using namespace std;

typedef pair<int, int> PII;
typedef array<int, 4> A4;

map<PII, int> input;
set<PII> st, points;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<PII> ans(n);
    PII p;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        input.insert(pair<PII, int>(p, i));
        points.insert(p);
        for (int j = 0; j < 4; j++) {
            st.insert(PII(p.first + dx[j], p.second + dy[j]));
        }
    }
    queue<array<int, 4> > q;
    for (auto iter = st.begin(); iter != st.end(); iter++) {
        int x = iter->first, y = iter->second;
        if (points.find(PII(x, y)) == points.end()) {
            q.push({x, y, x, y});
        }
    }
    while (!q.empty()) {
        A4 now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now[0] + dx[i], ny = now[1] + dy[i];
            if (points.find(PII(nx, ny)) != points.end()) {
                ans[input[PII(nx, ny)]] = PII(now[2], now[3]);
                points.erase(PII(nx, ny));
                q.push({nx, ny, now[2], now[3]});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}