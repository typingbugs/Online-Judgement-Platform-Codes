# include <iostream>

using namespace std;

string vika = "vika";
char input[20][20];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input[i][j];
    int index = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (input[i][j] == vika[index]) {
                index++;
                break;
            }
        }
        if (index >= 4) break;
    }
    if (index == 4) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}