#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct {
    string name;
    ll contribution;
    int level;
} Person;

string int2state[7] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao",
                       "TangZhu", "JingYing", "BangZhong"};

int state2int(string s) {
    int ans = 6;
    for (; ans >= 0 && s != int2state[ans]; ans--) ;
    return ans;
}

bool cmp_level(Person a, Person b) {
    return a.level > b.level;
}

bool cmp_contribution(Person a, Person b) {
    return a.contribution > b.contribution;
}

int main() {
    int n;
    cin >> n;
    vector<Person> list, vise_list;
    Person leader;
    for (int i = 0; i < n; i++) {
        Person person;
        string s;
        cin >> person.name >> s >> person.contribution >> person.level;
        int state = state2int(s);
        if (state == 0) leader = person;
        else if (state == 1) vise_list.push_back(person);
        else list.push_back(person);
    }

    cout << leader.name << ' ' << "BangZhu" << ' ' << leader.level << '\n';

    stable_sort(vise_list.begin(), vise_list.end(), cmp_level);
    for (auto p: vise_list) cout << p.name << ' ' << "FuBangZhu" << ' ' << p.level << '\n';

    if (!list.empty()) stable_sort(list.begin(), list.end(), cmp_contribution);
    int num[5] = {2, 4, 7, 25, 999999};
    int start = 0;
    for (int i: num) {
        if (start + i <= list.size()) {
            stable_sort(list.begin() + start, list.begin() + start + i, cmp_level);
            start += i;
        } else {
            stable_sort(list.begin() + start, list.end(), cmp_level);
            break;
        }
    }
    int num_index = 0, state_index = 2;
    for (auto p: list) {
        cout << p.name << ' ' << int2state[state_index] << ' ' << p.level << '\n';
        num[num_index]--;
        if (num[num_index] == 0) {
            num_index++;
            state_index++;
        }
    }
    return 0;
}
