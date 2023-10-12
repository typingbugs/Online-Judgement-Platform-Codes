#include <cstdio>

int main()
{
	char out[6];
	out[5] = 0;
	int i = 5;
	while (i--)
		out[i] = getchar();
	printf("%s\n", out);
	return 0;
}