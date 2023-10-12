#include<bits/stdc++.h>

using namespace std;

map<long long, int> nums;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        long long ans = n;
        for (int i = 0; i < n; i++) {
            int input;
            scanf("%d", &input);
            nums[input]++;
        }
        for (auto i = nums.begin(); i != nums.end(); i++) {
            if (i->second > 0 && nums[i->first * x] > 0) {
                if (i->second > nums[i->first * x]) {
                    ans -= 2 * nums[i->first * x];
                    nums[i->first * x] = 0;
                } else {
                    ans -= 2 * i->second;
                    nums[i->first * x] -= i->second;
                }
            }
        }
        printf("%lld\n", ans);
        nums.clear();
    }
    return 0;
}