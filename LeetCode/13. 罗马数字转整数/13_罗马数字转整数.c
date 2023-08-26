int romanToInt(char* s)
{
	int ans = 0, i, j, k;
	char words[9] = { 'I','V','X','L','C','D','M',1, 1 };
	char num[5] = { 0 };
	for (k = 6; s[0] != words[k]; k--)
		;
	i = k / 2;
	i *= 2;
	for (j = 0; i >= 0; j += k, ans *= 10, i -= 2)
	{
		k = 0;
		int flag = 0;
		if (j == strlen(s))
			continue;
		else if (i == 6)
		{
			while (s[j + k] != 'D' && s[j + k] != 'C' && s[j + k] != 0)
			{
				if (s[j + k] == 'L' || s[j + k] == 'X')
				{
					flag = 1;
					break;
				}
				else if (s[j + k] == 'V' || s[j + k] == 'I')
				{
					flag = 2;
					break;
				}
				k++;
			}
		}
		else if (i == 4)
		{
			while (s[j + k] != 'L' && s[j + k] != 'X' && s[j + k] != 0)
			{
				if (s[j + k] == 'V' || s[j + k] == 'I')
				{
					flag = 1;
					break;
				}
				k++;
			}
		}
		else if (i == 2)
		{
			while (s[j + k] != 'V' && s[j + k] != 'I' && s[j + k] != 0)
				k++;
		}
		else
			k = strlen(s) - j;
		if (s[j] == words[i])
		{
			if (s[j + 1] == words[i + 2])
				ans += 9;
			else if (s[j + 1] == words[i + 1])
				ans += 4;
			else
				ans += k;
		}
		else
			ans += (4 + k);
		if (flag)
		{
			for (; flag; flag--)
			{
				ans *= 10;
				i -= 2;
			}
		}
	}
	return ans / 10;
}