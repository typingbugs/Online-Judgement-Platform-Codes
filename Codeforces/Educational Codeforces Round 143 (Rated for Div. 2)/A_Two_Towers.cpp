#include <iostream>
#include <vector>

using namespace std;

bool solve() {
    int a, b;
    cin >> a >> b;
    getchar();
    vector<bool> s(a + b);
    for (int i = 0; i < a; i++) {
        s[i] = (getchar() == 'R');
    }
    getchar();
    for (int i = 0; i < b; i++) {
        s[a + b - 1 - i] = (getchar() == 'R');
    }
    getchar();
    int cnt = 0;
    for (int i = 0; i < a + b - 1; i++) {
        if (s[i] == s[i + 1]) {
            cnt++;
        }
    }
    if (cnt > 1) return false;
    else return true;
}


int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        printf("%s\n", (solve() ? "YES" : "NO"));
    }
    return 0;
}
