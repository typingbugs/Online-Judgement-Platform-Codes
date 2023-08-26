int reverse(int x)
{
	if (x == -2147483648)
		return 0;
	int check = 0;
	if (x < 0)
	{
		check = 1;
		x = -x;
	}
	int ans = 0;
	int i, max = 0;
	int times[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
	int alarm = 1;
	int maxNum[10] = { 2,1,4,7,4,8,3,6,4,7 };
	for (i = 1; x / i != 0 && i <= 100000000; i *= 10, max++)
		;
	if (x / i != 0)
		max++;
	for (i = 0; i < max; x /= 10, i++)
	{
		if (max == 10 && x % 10 > maxNum[i] && alarm == 1)
			return 0;
		else if (max == 10 && x % 10 < maxNum[i] && alarm)
			alarm = 0;
		ans = ans * 10 + x % 10;//可以避免不停乘不同的数量级
		//y += x % 10 * times[max - i - 1];不足的算法
	}
	if (check)
		return -ans;
	else
		return ans;
}
