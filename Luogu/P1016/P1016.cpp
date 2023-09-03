#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define eps 1E-9

using PDD = pair<double, double>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double D, C, disPerOil, P, N;
    cin >> D >> C >> disPerOil >> P >> N;
    vector<PDD> station(N + 2);
    station[0].second = P;
    station[N + 1].first = D;
    for (int i = 1; i <= N; i++) {
        cin >> station[i].first >> station[i].second;
    }

    int location = 0;
    double ans = 0, leftOil = 0;
    while (location < N + 1) {
        double maxdis = station[location].first + C * disPerOil;
        if (D - maxdis > eps && station[location + 1].first - maxdis > eps) {
            printf("No Solution\n");
            return 0;
        }
        int minprice = location, i = location + 1;
        for (; i <= N && station[i].first - maxdis < eps; i++) {
            if (station[i].second - station[minprice].second < eps) {
                minprice = i;
                break;
            }
        }
        if (minprice == location) {
            if (D - maxdis > eps) {
                i = location + 1, minprice = location + 1;
                for (; i <= N && station[i].first - maxdis < eps; i++) {
                    if (station[i].second - station[minprice].second < eps) {
                        minprice = i;
                    }
                }
                ans += (C - leftOil) * station[location].second;
                leftOil = C - (station[minprice].first - station[location].first) / disPerOil;
                location = minprice;
            }
            else {
                ans += ((D - station[location].first) / disPerOil - leftOil) * station[location].second;
                location = N + 1;
            }
        }
        else {
            ans += ((station[minprice].first - station[location].first) / disPerOil - leftOil) * station[location].second;
            leftOil = 0;
            location = minprice;
        }
    }

    printf("%.2lf\n", ans);

    return 0;
}