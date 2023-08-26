#define bool int
#define true 1
#define false 0

bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	int times[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
	int i, max;
	int temp = x;
	for (max = 0; temp; temp /= 10, max++)
		;
	for (i = max / 2; i > 0; i--)//��λ���Ա�
	{
		if (max - i + 1 == 10)
		{
			if (x / times[max - i] != x % times[i] / times[i - 1])
				return false;//��Ҫ��10^10ȡģʱ�����������ʱȡģ�����ԭ�������Ե������ۣ���ȡģ����
		}
		else if (x % times[max - i + 1] / times[max - i] != x % times[i] / times[i - 1])
			return false;
	}
	return true;
}