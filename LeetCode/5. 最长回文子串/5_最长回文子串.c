#include<stdio.h>
#include<string.h>

char* longestPalindrome(char* s)
{
	int i;
	int lenMax = 1;
	int maxPos = 0;
	int L, R;
	if (s[1] == s[0])
		lenMax = 2;
	for (i = 2; i < strlen(s); i++)
	{
		if (s[i] == s[i - 2])//奇数个字符对称
		{
			if (3 > lenMax)
			{
				maxPos = i - 2;
				lenMax = 3;
			}
			L = i - 3;
			R = i + 1;
			while (L >= 0 && R < strlen(s))
			{
				if (s[L] == s[R])
				{
					if (3 + 2 * (R - i) > lenMax)
					{
						lenMax = 3 + 2 * (R - i);
						maxPos = L;
					}
					L--;
					R++;
				}
				else
					break;
			}
		}
		if (s[i] == s[i - 1])//偶数个字符对称
		{
			if (2 > lenMax)
			{
				maxPos = i - 1;
				lenMax = 2;
			}
			L = i - 2;
			R = i + 1;
			while (L >= 0 && R < strlen(s))
			{
				if (s[L] == s[R])
				{
					if (2 + 2 * (R - i) > lenMax)
					{
						lenMax = 2 + 2 * (R - i);
						maxPos = L;
					}
					L--;
					R++;
				}
				else
					break;
			}
		}
	}
	s[maxPos + lenMax] = '\0';
	return s + maxPos;
}

int main()
{
	char str[1001];
	scanf("%s", str);
	char* p;
	p = longestPalindrome(str);
	printf("%s", p);
	return 0;
}