#include<bits/stdc++.h>

using namespace std;

void solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		solve();
	}
	return 0;
}

int a[52];

void solve()
{
	int len, even_cnt = 0;
	scanf("%d", &len);
	for (int i = 1; i <= len; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0)
			even_cnt++;
	}
	if (even_cnt % 2 == 0)
		printf("YES\n");
	else
	{
		sort(a + 1, a + len + 1);
		bool f = 0;
		for (int i = 1; i < len; i++)
		{
			if (a[i] + 1 == a[i + 1])
			{
				f = 1;
				break;
			}
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
}