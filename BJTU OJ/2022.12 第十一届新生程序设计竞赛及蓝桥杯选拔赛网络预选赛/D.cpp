#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int tmp = 0;
    cin >> tmp;
    n--;
    while (n--) {
        int input = 0;
        cin >> input;
        int dif = input - tmp - m;
        ans += dif > 0 ? dif : 0;
        tmp = input;
    }
    cout << ans << endl;
    return 0;
}