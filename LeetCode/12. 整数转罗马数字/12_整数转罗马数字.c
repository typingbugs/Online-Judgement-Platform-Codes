char ans[16];
char* intToRoman(int num)
{
	int a, i = 0, num1 = 0, j = 0, k;
	do
	{
		i++;
		num1 = num1 * 10 + num % 10;
	} while (num /= 10);//·´×ª
	char roman[4][2] = { {'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M','\0'} };
	do
	{
		i--;
		a = num1 % 10;
		if (a == 0)
			continue;
		else if (a <= 3)
			for (k = 0; k < a; k++)
				ans[j++] = roman[i][0];
		else if (a == 4)
		{
			ans[j++] = roman[i][0];
			ans[j++] = roman[i][1];
		}
		else if (a == 5)
			ans[j++] = roman[i][1];
		else if (a <= 8)
		{
			ans[j++] = roman[i][1];
			for (k = 0; k < a - 5; k++)
				ans[j++] = roman[i][0];
		}
		else
		{
			ans[j++] = roman[i][0];
			ans[j++] = roman[i + 1][0];
		}
	} while (num1 /= 10);
	ans[j] = '\0';
	return ans;
}