#include <iostream>

using namespace std;

bool solve() {
    int n, k;
    cin >> n >> k;
    int a, b;
    int l = -1, r = 10000;
    while (n--) {
        cin >> a >> b;
        if (a <= k && k <= b) {
            l = max(l, a);
            r = min(r, b);
        }
    }
    if (l == r) return true;
    else return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) printf("%s\n", (solve() ? "YES" : "NO"));
    return 0;
}