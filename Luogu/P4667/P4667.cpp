#include<bits/stdc++.h>
using namespace std;

const int Nmax = 500;
const int dx[4] = { 1, 1, -1, -1 };
const int dy[4] = { 1, -1, 1, -1 };
using PII = pair<int, int>;

vector<vector<bool> > p;
int N, M;
int ans = 1E9, vis[Nmax][Nmax], minturn[Nmax][Nmax];

void dbfs() {
    bool flag;
    queue<PII> st, tar;
    st.push(PII(0, 0));
    tar.push(PII(N, M));
    while (!st.empty() && !tar.empty()) {
        PII now;
        if (st.size() >= tar.size()) {
            now = st.front();
            st.pop();
            flag = 0;
        }
        else {
            now = tar.front();
            tar.pop();
            flag = 1;
        }
        for (int i = 0; i < 4; i++) {
            PII next = PII(now.first + dx[i], now.second + dy[i]);
            if (next.first > )
        }
    }
}

int main() {
    scanf("%d %d\n", &N, &M);
    p.resize(N);
    char in;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            minturn[i][j] = 1E9;
            if ((in = getchar()) == '/') {
                p[i].push_back(0);
            }
            else {
                p[i].push_back(1);
            }
        }
        getchar();
    }
    dbfs();
    return 0;
}