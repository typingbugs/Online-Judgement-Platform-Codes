#include<iostream>

using namespace std;

int main() {
    int input;
    cin >> input;
    bool flag = 0;
    int i = 2;
    for (; i * i < input; i++) {
        if (input % i == 0) {
            flag = 1;
            break;
        }
    }
    if (!flag && i * i == input) {
        flag = 1;
    }
    if (!flag) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << input - i - (input / i) + 2 << '\n';
    cout << i << " " << input / i;
    int n = input - i - (input / i);
    while (n--) {
        cout << " 1";
    }
    cout << '\n';
    return 0;
}