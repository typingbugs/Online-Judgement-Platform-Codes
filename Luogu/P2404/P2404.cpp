# include<bits/stdc++.h>

using namespace std;

vector<int> ans;
int n;

void dfs(int left) {
    if (left == 0) {
        for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << '+';
        cout << ans[ans.size() - 1] << '\n';
        return;
    }
    for (int i = ans[ans.size() - 1]; i <= left; i++) {
        if (left - i < i && left != i) continue;
        ans.push_back(i);
        dfs(left - i);
        ans.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n / 2; i++) {
        ans.push_back(i);
        dfs(n - i);
        ans.pop_back();
    }
    return 0;
}
