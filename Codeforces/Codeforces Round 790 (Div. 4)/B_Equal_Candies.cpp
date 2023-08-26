#include<cstdio>

int main()
{
	int times = 0, input = 0, len = 0;
	scanf("%d", &times);
	while (times--)
	{
		scanf("%d", &len);
		int min = 0;
		scanf("%d", &min);
		long long ans = 0;
		for (int i = 1; i < len; i++)
		{
			scanf("%d", &input);
			if (input > min)
				ans += input - min;
			else if (input < min)
			{
				ans += i * (min - input);
				min = input;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}