#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct {
    string name;
    ll contribution;
    int level;
} Person;

bool cmp_level(Person a, Person b) {
    return a.level > b.level;
}

bool cmp_contribution(Person a, Person b) {
    return a.contribution > b.contribution;
}

string int2state[7] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao",
                       "TangZhu", "JingYing", "BangZhong"};

int main() {
    int n;
    cin >> n;
    vector<Person> list;
    string tmp;

    Person leader;
    cin >> leader.name >> tmp >> leader.contribution >> leader.level;
    cout << leader.name << ' ' << "BangZhu" << ' ' << leader.level << '\n';

    for (int i = 1; i < 3; i++) {
        Person person;
        cin >> person.name >> tmp >> person.contribution >> person.level;
        cout << person.name << ' ' << "FuBangZhu" << ' ' << person.level << '\n';
    }

    for (int i = 3; i < n; i++) {
        Person person;
        cin >> person.name >> tmp >> person.contribution >> person.level;
        list.push_back(person);
    }
    if (!list.empty()) stable_sort(list.begin(), list.end(), cmp_contribution);
    int num[5] = {2, 4, 7, 25, 999};
    int start = 0;
    for (int i: num) {
        if (start + i < list.size()) {
            stable_sort(list.begin() + start, list.begin() + start + i, cmp_level);
            start += i;
        } else {
            stable_sort(list.begin() + start, list.end(), cmp_level);
            break;
        }
    }
    int index = 0;
    for (auto p: list) {
        cout << p.name << ' ' << int2state[index + 2] << ' ' << p.level << '\n';
        if (--num[index] == 0) index++;
    }
    return 0;
}
