#include<cstdio>
using namespace std;

long long bar[50001];

int main()
{
	int n = 0, max = 0;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);
		bar[input]++;
		max = max > input ? max : input;
	}
	for (int i = 0; i <= max; i++)
	{
		if (bar[i] == 0)
			continue;
		for (int j = 0; j < i; j++)
		{
			if (bar[j] == 0)
				continue;
			long long a = bar[i + j];
			if (a < 2)
				continue;
			ans = (ans + bar[i] * bar[j] * a * (a - 1) / 2) % 1000000007;
		}
		if (bar[i] >= 2)
		{
			long long a = bar[i * 2];
			if (a >= 2)
				ans = (ans + bar[i] * (bar[i] - 1) / 2 * a * (a - 1) / 2) % 1000000007;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

//map<int, int> num;
//
//int main()
//{
//	int n = 0, ans = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int input;
//		scanf("%d", &input);
//		num[input]++;
//	}
//	for (map<int, int>::iterator i = num.begin(); i != num.end(); ++i)
//	{
//		for (map<int, int>::iterator j = num.begin(); j != i; ++j)
//		{
//			int a = num[i->first + j->first];
//			if (a == 0)
//			{
//				num.erase(i->first + j->first);
//				continue;
//			}
//			else if (a < 2)
//				continue;
//			ans = (ans + i->second * j->second * a  * (a - 1) / 2) % (int)(1e9 + 7);
//		}
//		if (i->second >= 2)
//		{
//			int a = num[2 * i->first];
//			if (a == 0)
//				num.erase(2 * i->first);
//			else if (a >= 2)
//				ans = (ans + i->second * (i->second - 1) / 2 * a * (a - 1) / 2) % (int)(1e9 + 7);
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}