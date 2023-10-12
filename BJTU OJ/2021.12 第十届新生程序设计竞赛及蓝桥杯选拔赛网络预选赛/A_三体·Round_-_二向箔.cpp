#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m;
    __builtin_scanf("%d%d", &n, &m);
    int e[2];
    int v[2];
    int i, j;
    int checkE = 0, checkV = 0;
    char *p = NULL;
    p = (char *) malloc(sizeof(char) * (m + 1));
    if (p != NULL) {
        for (i = 0; i < n; i++) {
            __builtin_scanf("%s", p);
            for (j = 0; j < m; j++) {
                if (*(p + j) == 'E') {
                    e[0] = i;
                    e[1] = j;
                    checkE = 1;
                }
                if (*(p + j) == 'V') {
                    v[0] = i;
                    v[1] = j;
                    checkV = 1;
                }
            }
        }
        __builtin_printf("%d\n", (abs(e[0] - v[0]) > abs(e[1] - v[1]) ? abs(e[0] - v[0]) : abs(e[1] - v[1])));
    }
    free(p);
    p = NULL;
    return 0;
}