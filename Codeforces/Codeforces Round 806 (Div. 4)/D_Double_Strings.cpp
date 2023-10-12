#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

string s[100000];
unordered_set<string> ss;

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        int n;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            getline(cin, s[i]);
            ss.insert(s[i]);
        }
        for (int i = 0; i < n; i++) {
            bool flag = 0;
            int len = s[i].size();
            for (int j = 1; j < len; j++) {
                string a1 = s[i].substr(0, j), a2 = s[i].substr(j, 8);
                auto s1 = ss.find(a1), s2 = ss.find(a2);
                if (s1 != ss.end() && s2 != ss.end()) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        ss.clear();
    }
    return 0;
}