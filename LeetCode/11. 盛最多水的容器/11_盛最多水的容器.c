//双指针，官方文字题解一
int maxArea(int* height, int heightSize)
{
	int leftPos = 0, rightPos = heightSize - 1, area, ans = 0, left, right;
	while (leftPos < rightPos)
	{
		left = height[leftPos];
		right = height[rightPos];
		if (left > right)
		{
			area = (rightPos - leftPos) * right;
			ans = (ans > area ? ans : area);
			rightPos--;
		}
		else
		{
			area = (rightPos - leftPos) * left;
			ans = (ans > area ? ans : area);
			leftPos++;
		}
	}
	return ans;
}

//ver2太复杂，而且有无法修复的bug
//int data[100000][10000] = { 0 };
//int maxArea(int* height, int heightSize)
//{
//	int ans = 0, i, j, minPos, maxPos, pos;
//	for (i = 0; i < heightSize; i++)
//	{
//		data[height[i]][0]++;
//		data[height[i]][data[i][0]] = i;
//	}
//	for (i = 1; i < 100000; i++)
//	{
//		if (data[i][0])
//		{
//			if (data[i][0] - 1)//>=2
//			{
//				minPos = data[i][1];
//				maxPos = data[i][data[i][0]];
//				ans = (ans > i * (maxPos - minPos) ? ans : i * (maxPos - minPos));
//				for (j = i + 1; j < 100000; j++)
//				{
//					for (pos = data[j][0]; data[j][pos] > minPos && pos; pos--)
//						if (ans < i* (data[j][pos] - minPos))
//							ans = i * (data[j][pos] - minPos);
//					for (pos = 1; data[j][pos] < maxPos && pos <= data[j][0]; pos++)
//						if (ans < i * (maxPos - data[j][pos]));
//							ans = i * (maxPos - data[j][pos]);
//				}
//			}
//			else//=1
//			{
//				minPos = data[i][1];
//				for (j = i + 1; j < 100000; j++)
//					for (pos = 1; pos <= data[j][0]; pos++)
//						if (ans < i * (data[j][pos] - minPos))
//							ans = i * (data[j][pos] - minPos);
//			}
//		}
//		else
//			continue;
//	}
//	return ans;
//}

//ver1:超时
//int maxArea(int* height, int heightSize)
//{
//	int ans = 0;
//	int i = 0, j;
//	for (i = 0; i < heightSize - 1; i++)
//		for (j = i + 1; j < heightSize; j++)
//		{
//			if (height[i] <= height[j])
//				ans = (height[i] * (j - i) > ans ? height[i] * (j - i) : ans);
//			else
//				ans = (height[j] * (j - i) > ans ? height[j] * (j - i) : ans);
//		}
//	return ans;
//}