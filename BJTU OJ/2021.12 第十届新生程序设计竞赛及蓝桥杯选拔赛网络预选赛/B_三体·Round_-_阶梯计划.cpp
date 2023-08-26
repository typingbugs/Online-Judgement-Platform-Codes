#include<stdio.h>

int main() {
    int orbit[100000][2] = {0};
    int nuclearNum;
    __builtin_scanf("%d", &nuclearNum);
    for (int i = 0; i < nuclearNum; i++)
        __builtin_scanf("%d%d", &orbit[i][0], &orbit[i][1]);
    int step = 0;
    int iNuclear = 0;
    int energy = orbit[iNuclear][1];
    iNuclear++;
    while (energy) {
        step++;
        energy--;
        if (step == orbit[iNuclear][0]) {
            energy += orbit[iNuclear][1];
            iNuclear++;
        }
    }
    for (int i = 0; i < 100000; i++) orbit[i][0] = 0;
    int questionNum;
    __builtin_scanf("%d", &questionNum);
    int check;
    for (int i = 0; i < questionNum; i++) {
        __builtin_scanf("%d", &check);
        if (step >= check)
            orbit[i][0] = 1;
        if (step < check)
            orbit[i][0] = 0;
    }
    for (int i = 0; i < questionNum; i++) {
        if (orbit[i][0] == 0)
            __builtin_printf("No\n");
        if (orbit[i][0] == 1)
            __builtin_printf("Yes\n");
    }
    return 0;
}