#include<cstdio>

int main()
{
	int times = 0;
	scanf("%d", &times);
	while (times--) {
		printf("Division ");
		int rating = 0;
		scanf("%d", &rating);
		if (rating <= 1399) rating = 4;
		else if (rating <= 1599) rating = 3;
		else if (rating <= 1899) rating = 2;
		else rating = 1;
		printf("%d\n", rating);
	}
	return 0;
}