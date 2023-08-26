char ans[1001];

char* convert(char* s, int numRows)
{
	if (numRows == 1)
		return s;
	int cir = 2 * (numRows - 1);
	int i, j, k = 0;
	int len = strlen(s);
	for (j = 0; j < len; j += cir)
			ans[k++] = s[j];
	for (i = 1; i < numRows - 1; i++)
		for (j = 0; j < len + cir - 1; j += cir)
		{
			if (j - i >= 0 && j - i < len)
				ans[k++] = s[j - i];
			if (j + i < len)
				ans[k++] = s[j + i];
		}
	for (j = numRows - 1; j < len; j += cir)
			ans[k++] = s[j];
	ans[len] = '\0';
	return ans;
}