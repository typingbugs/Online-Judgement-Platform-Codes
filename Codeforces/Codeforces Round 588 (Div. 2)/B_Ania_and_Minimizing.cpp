#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string in;
    cin >> in;
    if(n == 1 && m > 0){
        cout << "0\n";
        return 0;
    }
    if (m) {
        if (in[0] != '1') {
            in[0] = '1';
            m--;
        }
        for (int i = 1; m > 0 && i < n; i++) {
            if (in[i] != '0') {
                in[i] = '0';
                m--;
            }
        }
    }
    cout << in << '\n';
    return 0;
}

