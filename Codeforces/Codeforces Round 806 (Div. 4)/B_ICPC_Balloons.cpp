#include<cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) {
        bool p[26] = {0};
        int len, ans = 0;
        scanf("%d", &len);
        getchar();
        while (len--) {
            char in = getchar();
            if (p[in - 'A'] == 0) {
                p[in - 'A'] = true;
                ans += 2;
            } else
                ans += 1;
        }
        getchar();
        printf("%d\n", ans);
    }
    return 0;
}