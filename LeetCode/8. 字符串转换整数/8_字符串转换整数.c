int myAtoi(char* s)
{
	int st, end;
	int neg = 0;
	int i, j;
	long ans = 0;
	for (i = 0; s[i] == ' '; i++)
		;//ȥ��ǰ��Ŀո�
	if (s[i] != '-' && s[i] != '+' && (s[i] < '0' || s[i]>'9'))
		return 0;//��һ���ǿո�������Ƿ��Ż������־����0
	if (s[i] == '-')
	{
		neg = 1;
		st = i + 1;
	}
	else if (s[i] >= '0' && s[i] <= '9')
		st = i;
	else
		st = i + 1;
	int notZero = 1;//�������ֿ�ʼ�ͽ����Լ�����
	for (end = st, j = 0; s[end] >= '0' && s[end] <= '9'; end++, j++)
	{
		if (s[end] != '0')
			notZero = 0;
		if (notZero)
			j--;
		if (j > 10)
			break;
	}//��ǰ���0���ԣ�Ȼ���ж��Ƿ񳬹�10λ��
	if (j > 10)
	{
		if (neg)
			return -2147483648;
		else
			return 2147483647;
	}//������ֱ�����
	end--;
	for (; end - st + 1; st++)
		ans = ans * 10 + s[st] - '0';//û������λ����
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
	}//������
}//ע����Ŀ����һ��Ҫ�����Ҫ��