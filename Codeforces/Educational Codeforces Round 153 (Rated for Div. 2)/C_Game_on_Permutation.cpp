# include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int min_of_lose_point, min_not_lose_point = 9999999, input;
    cin >> input;
    min_of_lose_point = input;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> input;
        if (input < min_of_lose_point) {
            min_of_lose_point = input;
            // There is no smaller point in front of this point.
            // So who choose this point will lose.
            // Call it lose-point.
        } else if (input < min_not_lose_point) {
            min_not_lose_point = input;
            ans++;
            // There is no smaller NOT-lose-point in front of this point.
            // So the next player must choose a lose-point.
            // So who choose the point will win.
        }
    }
    cout << ans << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}