#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> s(1001);
    while (n--) {
        int input = 0;
        cin >> input;
        s[input] = true;
    }
    unsigned long long ans = 0;
    for (int i = 1; i < 1001; i++) {
        if (s[i])ans += i;
    }
    cout << ans * 2 << endl;
    return 0;
}