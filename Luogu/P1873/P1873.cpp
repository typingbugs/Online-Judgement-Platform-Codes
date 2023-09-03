#include<cstdio>
#include<algorithm>
using namespace std;

int wood[1000002];

int main()
{
	int M = 0;
	scanf("%d %d", &wood[0], &M);
	for (int i = 1; i <= wood[0]; i++)
	{
		scanf("%d", &wood[i]);
	}
	sort(wood + 1, wood + wood[0] + 1);
	int l = 0, r = wood[wood[0]];
	long long sum = 0;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		sum = 0;
		for (int i = wood[0]; wood[i] > mid && i > 0; i--)
			sum += wood[i] - mid;
		if (sum < M)
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%d\n", l - 1);
	return 0;
}