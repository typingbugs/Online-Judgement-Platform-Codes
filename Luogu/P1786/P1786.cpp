#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct {
    string name;
    int state;
    ll contribution;
    int level;
} Person;

string int2state[7] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao",
                       "TangZhu", "JingYing", "BangZhong"};

int state2int(string s) {
    if (s == "BangZhu") return 0;
    if (s == "FuBangZhu") return 1;
    if (s == "HuFa") return 2;
    if (s == "ZhangLao") return 3;
    if (s == "TangZhu") return 4;
    if (s == "JingYing") return 5;
    return 6;
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
        person.state = state2int(s);
        if (person.state == 0) leader = person;
        else if (person.state == 1) vise_list.push_back(person);
        else list.push_back(person);
    }

    cout << leader.name << ' ' << int2state[leader.state] << ' ' << leader.level << '\n';

    stable_sort(vise_list.begin(), vise_list.end(), cmp_level);
    for (auto p: vise_list) cout << p.name << ' ' << int2state[p.state] << ' ' << p.level << '\n';

    if (!list.empty()) stable_sort(list.begin(), list.end(), cmp_contribution);
    int num[5] = {2, 4, 7, 25, 999999};
    int start = 0;
    for (int i = 0; i < 4; i++) {
        if (start + num[i] <= list.size()) {
            stable_sort(list.begin() + start, list.begin() + start + num[i], cmp_level);
            start += num[i];
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
