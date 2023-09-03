#include<iostream>
#include<cstdio>
#include<map>
//#include<bits/stdc++.h>
using namespace std;
int a[200001];
map<int,int> m;
int main()
{
	long long ans = 0;
	int c;
	int N;
	scanf("%d%d", &N, &c);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		m[a[i]]++;
		a[i] -= c;
	}
	for (int i = 1; i <= N; i++)
		ans += m[a[i]];
	printf("%lld\n", ans);
	return 0;
}