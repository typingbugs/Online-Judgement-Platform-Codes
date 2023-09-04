#include<bits/stdc++.h>

using namespace std;
int n;
int num;

pair<int, int> merge(int i) {
    if (i == n - 1 && i != 0) {
        return min(merge(i - 1), merge(i - 1));
    } else if (i == n - 1 && i == 0) {
        int a, b;
        cin >> a >> b;
        num += 2;
        return min(pair<int, int>(a, num - 2), pair<int, int>(b, num - 1));
    } else if (i == 0) {
        int a, b;
        cin >> a >> b;
        num += 2;
        return max(pair<int, int>(a, num - 2), pair<int, int>(b, num - 1));
    } else {
        return max(merge(i - 1), merge(i - 1));
    }
}

int main() {
    cin >> n;
    cout << merge(n - 1).second + 1 << endl;
    return 0;
}