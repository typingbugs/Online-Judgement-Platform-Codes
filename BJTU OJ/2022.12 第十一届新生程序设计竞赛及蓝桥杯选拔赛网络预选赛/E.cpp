#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[7];
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
    int pos = 1;
    int m = -1;
    for (int i = 1; i <= 6; i++) {
        if (a[i] > m) {
            m = a[i];
            pos = i;
        }
    }
    if (pos != 1) {
        cout << pos << endl;
    } else {
        cout << "OMG!!!NO!!!" << endl;
    }
    return 0;
}