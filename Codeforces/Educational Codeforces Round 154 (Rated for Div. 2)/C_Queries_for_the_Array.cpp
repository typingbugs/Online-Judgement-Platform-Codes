#include <iostream>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<char> state;
    state.push_back('1');
    for (auto c: s) {
        if (c == '1') {
            int i = state.size() - 1;
            while (state[i] != '1') {
                if (state[i] == '0') {
                    cout << "NO\n";
                    return;
                } else state[i] = '1';
                i--;
            }
        } else if (c == '0') {
            if (state.size() < 2) {
                cout << "NO\n";
                return;
            }
            if (state[state.size() - 1] == '1') {
                cout << "NO\n";
                return;
            }
            state[state.size() - 1] = '0';
        } else if (c == '+') {
            if (state.size() < 2) state.push_back('1');
            else state.push_back('?');
        } else if (c == '-') {
            if (state.size() < 1) {
                cout << "NO\n";
                return;
            } else state.pop_back();
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
