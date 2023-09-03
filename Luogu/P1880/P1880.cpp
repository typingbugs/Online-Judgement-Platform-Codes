#include<bits/stdc++.h>
using namespace std;

int rocks[101][101][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> rocks[0][i][0];
        rocks[0][i][1] = rocks[0][i][0];
    }
    for (int i = 1; i < N; i++) {
        int max = 0, min = 1000;
        int max_tmp = rocks[0][1][0], max_pos[2];
        int min_tmp = rocks[0][1][1], min_pos[2];
        for (int j = 1; j < N - i + 1; j++) {
            if (max_tmp + rocks[i - 1][j][0] > max) {
                max_pos[0] = i - 1;
                max_pos[1] = i;
                max = max_tmp + rocks[i - 1][j][0];
            }
            if (min_tmp + rocks[i - 1][j][1] < min) {
                min_pos[0] = i - 1;
                min_pos[1] = i;
                min = min_tmp + rocks[i - 1][j][1];
            }
            max_tmp = rocks[i - 1][j][0];
            min_tmp = rocks[i - 1][j][1];
        }
        for (int j = 1; j < max_pos[0]; j++) {
            rocks[i][j][0] = rocks[i - 1][j][0];
        }
        rocks[i][max_pos[0]][]
    }

    return 0;
}