#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;

int main() {
	int n;
	cin >> n;
	string a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		m[a]++;
	}
	int x = -1;
	bool flag = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		if (x < i->second) {
			x = i->second;
			flag = 0;
		}
		else if (x == i->second) {
			flag = 1;
		}
	}
	if (flag || x <= n / 2) {
		cout << "NONE" << '\n';
	}
	else {
		for (auto i = m.begin(); i != m.end(); i++) {
			if (i->second == x) {
				cout << i->first << '\n';
			}
		}
	}
	return 0;
}