#include<stdio.h>

int let[26][200001];
char w[200001];

int main()
{
	int t = 0;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		for (int i = 0; i < 26; i++)
			let[i][0] = 0;
		int sum = 0, len = 0;
		while ((w[len] = getchar()) != '\n')
		{
			int dif = w[len] - 'a';
			let[dif][0]++;
			let[dif][let[dif][0]] = len;
			sum += dif + 1;
			len++;
		}
		int count[26];
		for (int i = 0; i < 26; i++)
			count[i] = let[i][0];
		int p = 0;
		scanf("%d", &p);
		getchar();
		for (int i = 25; i >= 0; i--)
		{
			while (sum > p && let[i][0] != 0)
			{
				let[i][0]--;
				sum -= i + 1;
				w[let[i][count[i] - let[i][0]]] = 0;
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (w[i] != 0)
				printf("%c", w[i]);
		}
		printf("\n");
	}
	return 0;
}