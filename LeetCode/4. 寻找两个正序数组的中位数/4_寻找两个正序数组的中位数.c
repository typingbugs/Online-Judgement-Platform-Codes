#include<stdio.h>
#include<stdlib.h>

int s1[1001], s2[1001];

//����鲢���򡰷��Ρ��С��Ρ���˼��
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int pos1 = 0, pos2 = 0, count = 0;
	int record = 0;
	if ((nums1Size + nums2Size) % 2)//�棬�м�һ��
	{
		while (count < (nums1Size + nums2Size) / 2 && pos1 < nums1Size && pos2 < nums2Size)
			if (nums1[pos1] <= nums2[pos2])
			{
				pos1++;
				count++;
			}
			else
			{
				pos2++;
				count++;
			}
		if (pos1 < nums1Size && pos2 < nums2Size)
			if (nums1[pos1] <= nums2[pos2])
				return nums1[pos1];
			else
				return nums2[pos2];
		if (pos1 < nums1Size)
			while (count < (nums1Size + nums2Size) / 2)
			{
				pos1++;
				count++;
			}
		if (pos1 < nums1Size)
			return nums1[pos1];
		if (pos2 < nums2Size)
			while (count < (nums1Size + nums2Size) / 2)
			{
				pos2++;
				count++;
			}
		if (pos2 < nums2Size)
			return nums2[pos2];
	}
	else//ż���м�����ƽ��ֵ
	{
		while (count < (nums1Size + nums2Size) / 2 - 1 && pos1 < nums1Size && pos2 < nums2Size)
			if (nums1[pos1] <= nums2[pos2])
			{
				pos1++;
				count++;
			}
			else
			{
				pos2++;
				count++;
			}
		if (pos1 < nums1Size && pos2 < nums2Size)
		{
			if (nums1[pos1] <= nums2[pos2])
				record = nums1[pos1++];
			else
				record = nums2[pos2++];
		}
		if (pos1 < nums1Size && pos2 < nums2Size)
		{
			if (nums1[pos1] <= nums2[pos2])
				return ((double)record + (double)nums1[pos1]) / 2;
			else
				return ((double)record + (double)nums2[pos2]) / 2;
		}
		if (pos1 < nums1Size)
		{
			while (count < (nums1Size + nums2Size) / 2 - 1)
			{
				pos1++;
				count++;
			}
			if (!record)
				record = nums1[pos1++];
			return ((double)record + (double)nums1[pos1]) / 2;
		}
		if (pos2 < nums2Size)
		{
			while (count < (nums1Size + nums2Size) / 2 - 1)
			{
				pos2++;
				count++;
			}
			if (!record)
				record = nums2[pos2++];
			return ((double)record + (double)nums2[pos2]) / 2;
		}
	}
}

int main()
{
	int m, n, i;
	printf("��ֱ�����s1��s2�ĳ���\n");
	scanf("%d %d", &m, &n);
	printf("���s1��ֵ\n");
	for (i = 0; i < m; i++)
		scanf("%d", &s1[i]);
	printf("���s2��ֵ\n");
	for (i = 0; i < n; i++)
		scanf("%d", &s2[i]);
	printf("%.5lf\n", findMedianSortedArrays(s1, m, s2, n));
	return 0;
}