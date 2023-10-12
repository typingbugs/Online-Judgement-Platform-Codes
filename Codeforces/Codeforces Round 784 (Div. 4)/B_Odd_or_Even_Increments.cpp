#include<cstdio>

int main() {
    int time = 0, len = 0, input = 0;
    scanf("%d", &time);
    while (time--) {
        scanf("%d", &len);
        if (len == 1 || len == 2) {
            for (int i = 0; i < len; i++) scanf("%d", &input);
            printf("YES\n");
            continue;
        }

        bool num[2] = {false};
        for (int i = 0; i < 2; i++) {
            scanf("%d", &input);
            num[1 - i] = input % 2;
        }
        bool fail = false;
        for (int i = 3; i <= len; i++) {
            scanf("%d", &input);
            if (input % 2 != num[i % 2])
                fail = true;
        }
        if (!fail)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}