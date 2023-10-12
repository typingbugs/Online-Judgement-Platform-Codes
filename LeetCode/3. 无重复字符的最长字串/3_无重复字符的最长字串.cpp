#include<bits/stdc++.h>
#include<map>
using namespace std;

char str[50001];

int lengthOfLongestSubstring(char* s)
{
	int map[256] = { 0 }, num, mark[256], i, j, k, max = 0, count = 0;
	for (j = 0; j < 256; j++)
		mark[j] = -1;
	for (i = 0; i < strlen(s); i++)
	{
		num = s[i];
		if (map[num] == 0)
		{
			map[num]++;
			mark[count] = num;
			count++;
		}
		else if (map[num] == 1)
		{
			max = (max > count ? max : count);
			for (k = 0; mark[k] != num; k++)
				map[mark[k]]--;
			for (j = 0; j < count - k - 1; j++)
				mark[j] = mark[j + k + 1];
			mark[j] = num;
			for (j++; j < count; j++)
				mark[j] = -1;
			count -= k;
		}
	}
	max = (max > count ? max : count);
	return max;
}

int main()
{
	scanf("%s", str);
	printf("%d\n", lengthOfLongestSubstring(str));
	return 0;
}