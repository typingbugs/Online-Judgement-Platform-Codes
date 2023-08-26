#include<stdio.h>

const double m[8] = {0, 261.6, 293.6, 329.6, 349.2, 392, 440, 493.8};
int cn[8];
int n, cnt;
double ans;

int main() {
    char input;
    while ((input = getchar()) != '\n') {
        if (input != '-') {
            n = input - '0';
        }
        cn[n]++;
        cnt++;
    }
    for (int i = 1; i < 8; i++) {
        ans += (m[i] * cn[i] / cnt);
    }
    printf("%lf\n", ans);
    return 0;
}