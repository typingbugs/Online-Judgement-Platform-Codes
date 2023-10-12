#include<cstdio>

using namespace std;
bool miss[500001] = {false};
bool check[500001] = {false};
int ans[500001];
int unread = 0;

int main() {
    int n, m, c, loss;
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &loss);
        miss[loss] = true;
    }
    for (int j = 0; j < c; j++) {
        int R;
        scanf("%d", &R);
        if (check[R])
            printf("%d\n", ans[R]);
        else {
            for (int i = R; i <= n; i += R)
                if (miss[i])
                    unread++;
            int a = n / R - unread;
            printf("%d\n", a);
            check[R] = true;
            ans[R] = a;
            unread = 0;
        }
    }
    return 0;
}