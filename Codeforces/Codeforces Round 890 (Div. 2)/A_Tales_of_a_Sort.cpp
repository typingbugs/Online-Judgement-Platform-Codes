# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n), arr_sort(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr_sort[i] = arr[i];
    }
    sort(arr_sort.begin(), arr_sort.end());
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != arr_sort[i]) {
            cout << arr_sort[i] << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}