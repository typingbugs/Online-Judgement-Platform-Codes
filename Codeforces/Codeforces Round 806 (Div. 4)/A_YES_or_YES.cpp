#include<cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    char r[5] = "yes\n";
    while (t--) {
        char input;
        int flag = 1;
        for (int cnt = 0; cnt < 4; cnt++) {
            input = getchar();
            if ((input != r[cnt] && input != r[cnt] + ('A' - 'a') && cnt != 3) || (input != '\n' && cnt == 3)) {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else {
            while (getchar() != '\n');
            printf("NO\n");
        }
    }
    return 0;
}