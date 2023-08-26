#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len, sft;
    cin >> len >> sft;
    getchar();
    vector<char> s(len);
    for (int i = 0; i < len; i++) {
        s[i] = getchar();
        s[i] = (s[i] - 'a' - sft + 260000) % 26 + 'a';
    }
    for (int i = len - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}