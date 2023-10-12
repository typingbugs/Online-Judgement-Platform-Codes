#include<bits/stdc++.h>

using namespace std;
int str[141];

int main() {
    str[0] = 3;
    cout << "\"3\",";
    int n = 100;
    while (n--) {
        int s[141] = {0};
        int tmp = str[0];
        int cnt = 1;
        int pos = 0;
        for (int i = 1; i < 141; i++) {
            if (str[i] == 0) {
                s[pos++] = cnt;
                s[pos++] = tmp;
                break;
            }
            if (str[i] == tmp) {
                cnt++;
            } else {
                s[pos++] = cnt;
                s[pos++] = tmp;
                tmp = str[i];
                cnt = 1;
                if (pos >= 140) {
                    break;
                }
            }
        }
        cout << "\"";
        for (int i = 0; i < 100; i++) {
            if (s[i] != 0) {
                cout << s[i];
            }
            str[i] = s[i];
        }
        cout << "\","<<endl;
    }
    return 0;
}