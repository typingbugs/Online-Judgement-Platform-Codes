#define bool int
#define true 1
#define false 0

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	else
	{
		int i, max;
		int temp1 = x;
		for (max = 0; temp1; temp1 /= 10, max++)
			;
		int temp2 = x;
		for (i = 0; i < max / 2; i++)
		{
			temp1 = temp1 * 10 + temp2 % 10;
			temp2 /= 10;
		}//temp1最后是x的右半边反过来
		for (i = 0; i < max - max / 2; i++)
			x /= 10;//x最后只剩下左半边
		if (temp1 == x)
			return true;
		else
			return false;
	}
}