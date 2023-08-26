#include<bits/stdc++.h>
using namespace std;

class Num {
public:
	int pos[2];
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<Num> stu(N + 1);
	vector<bool> dl(N + 1);
	int first = 1;
	for (int i = 2; i <= N; i++) {
		int k;
		bool p;
		cin >> k >> p;
		stu[i].pos[p] = stu[k].pos[p];
		stu[i].pos[!p] = k;
		stu[stu[k].pos[p]].pos[!p] = i;
		stu[k].pos[p] = i;
		if (!p && k == first)
			first = i;
	}
	int M;
	cin >> M;
	while (M--) {
		int d;
		cin >> d;
		dl[d] = 1;
	}
	int now = first;
	while (now) {
		if (!dl[now]) {
			cout << now << " ";
		}
		now = stu[now].pos[1];
	}
	cout << '\n';
}


//链表，会被T
//#include<bits/stdc++.h>
//using namespace std;
//
//class Node {
//public:
//    int num;
//    Node* next;
//};
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int N;
//    cin >> N;
//    Node* head = new Node;
//    head->next = new Node;
//    head->next->num = 1;
//    head->next->next = NULL;
//    for (int i = 2; i <= N; i++) {
//        int k;
//        bool p;
//        cin >> k >> p;
//        Node* l = head, * r = head->next;
//        while (p && l->num != k || (!p && r->num != k)) {
//            l = r;
//            r = r->next;
//        }
//        Node* m = new Node;
//        m->next = r;
//        l->next = m;
//        m->num = i;
//    }
//    set<int> s;
//    int M;
//    cin >> M;
//    while (M--) {
//        int d;
//        cin >> d;
//        s.insert(d);
//    }
//    for (Node* p = head->next; p != NULL; p = p->next) {
//        if (s.find(p->num) == s.end()) {
//            cout << p->num << " ";
//        }
//    }
//    cout << '\n';
//    return 0;
//}