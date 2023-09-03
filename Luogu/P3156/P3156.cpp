#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int stu = 0, ques = 0;
	scanf("%d %d", &stu, &ques);
	int* num = (int*)malloc(sizeof(int) * stu);
	for (int i = 0; i < stu; i++)
	{
		scanf("%d", &num[i]);
	}
	while (ques--)
	{
		int ask = 0;
		scanf("%d", &ask);
		printf("%d\n", num[ask - 1]);
	}
	printf("\n");
	return 0;
}