#include<cstdio>

using namespace std;

int num[102];

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) {
        scanf("%d", &num[0]);
        getchar();
        for (int i = 1; i <= num[0]; i++) {
            scanf("%d", &num[i]);
            getchar();
        }
        for (int i = 1; i <= num[0]; i++) {
            int op;
            scanf("%d", &op);
            getchar();
            for (int j = 0; j < op; j++) {
                if (getchar() == 'D')
                    num[i] = (num[i] + 1) % 10;
                else
                    num[i] = (num[i] + 9) % 10;
            }
            getchar();
        }
        for (int i = 1; i <= num[0]; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}