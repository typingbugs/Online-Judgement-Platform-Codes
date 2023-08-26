#include<stdio.h>

int main()
{
	char let[4];
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		int ans = 1, count = 0;
		char c;
		while ((c = getchar()) != '\n')
		{
			int found = 0;
			for (int i = 1; i <= count; i++)
			{
				if (let[i] == c)
				{
					found = 1;
					break;
				}
			}
			if (found)
				continue;
			else
			{
				count++;
				if (count == 4)
				{
					count = 1;
					ans++;
				}
				let[count] = c;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}