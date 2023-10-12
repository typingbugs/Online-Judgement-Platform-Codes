# include <iostream>
# include <algorithm>

using namespace std;

int main() {
    string inputstr;
    cin >> inputstr;
    int num_1 = 0, num_0 = 0;
    for (auto c : inputstr) {
        if (c == '1') num_1++;
        else num_0++;
    }
    int num_all_pair = num_1 * num_0;
    int num_10_pair = 0;
    int tmp = num_0;
    for (auto c : inputstr) {
        if (c == '1') num_10_pair += tmp;
        else tmp--;
    }
    int num_01_pair = num_all_pair - num_10_pair;
    if (num_10_pair < num_01_pair) { //11001100(12:4) -> 01011100(9:7) -> 01001110(6:10) -> 01001101(5:11)
        reverse(inputstr.begin(), inputstr.end());
        swap(num_01_pair, num_10_pair);
    }
    int ans = 0;
    string copy_0, copy_1 = inputstr;
    int copy_num_10_pair = num_10_pair;
    while (num_10_pair > num_01_pair) {
        copy_0 = inputstr;
        int index_1 = 0;
        while (inputstr[index_1] != '1') index_1++;
        int index_0 = index_1;
        int pass_0 = 0, pass_1 = 0;
        while (++index_0 < inputstr.length()) {
            if (inputstr[index_0] != '0') {
                pass_1++;
                continue;
            }
            pass_0++;
            inputstr[index_0] = '1';
            inputstr[index_1] = '0';
            int dif = pass_0 + pass_1;
            num_10_pair -= dif;
            num_01_pair += dif;
            if (num_10_pair > num_01_pair) {
                copy_1 = inputstr;
                copy_num_10_pair = num_10_pair;
                inputstr = copy_0;
                num_10_pair += dif;
                num_01_pair -= dif;
            } else {
                ans++;
                if (num_10_pair == num_01_pair) break;
                inputstr = copy_1;
                copy_0 = copy_1;
                num_10_pair = copy_num_10_pair;
                num_01_pair = num_all_pair - num_10_pair;
                break;
            }

        }
    }
    cout << ans << endl;
    return 0;
}