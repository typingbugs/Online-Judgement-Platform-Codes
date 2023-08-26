#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	char nums[11];
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		int max = 0;
		char num;
		while ((num = getchar()) != '\n')
		{
			nums[max++] = num;
		}
		nums[max] = '\0';
		nums[0] = '0' + nums[0] - '1';
		char* s = nums;
		while (*s == '0')
			s++;
		if (strlen(s) == 0)
			printf("0\n");
		else
			printf("%s\n", s);
	}
	return 0;
}