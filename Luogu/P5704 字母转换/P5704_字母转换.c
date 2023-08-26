#include <stdio.h>

int main()
{
	char input;
	scanf("%c", &input);
	printf("%c\n", input - 'a' + 'A');
	return 0;
}