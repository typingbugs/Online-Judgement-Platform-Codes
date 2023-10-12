int myAtoi(char* s)
{
	int st, end;
	int neg = 0;
	int i, j;
	long ans = 0;
	for (i = 0; s[i] == ' '; i++)
		;//去掉前面的空格
	if (s[i] != '-' && s[i] != '+' && (s[i] < '0' || s[i]>'9'))
		return 0;//第一个非空格如果不是符号或者数字就输出0
	if (s[i] == '-')
	{
		neg = 1;
		st = i + 1;
	}
	else if (s[i] >= '0' && s[i] <= '9')
		st = i;
	else
		st = i + 1;
	int notZero = 1;//设置数字开始和结束以及符号
	for (end = st, j = 0; s[end] >= '0' && s[end] <= '9'; end++, j++)
	{
		if (s[end] != '0')
			notZero = 0;
		if (notZero)
			j--;
		if (j > 10)
			break;
	}//把前面的0忽略，然后判断是否超过10位数
	if (j > 10)
	{
		if (neg)
			return -2147483648;
		else
			return 2147483647;
	}//超过了直接输出
	end--;
	for (; end - st + 1; st++)
		ans = ans * 10 + s[st] - '0';//没超过按位计算
	if (neg)
	{
		if (ans > 2147483648)
			ans = 2147483648;
		return (int)(-ans);
	}
	else
	{
		if (ans > 2147483647)
			ans = 2147483647;
		return (int)ans;
	}//最后输出
}//注意题目长的一定要审清楚要求