#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;
	
	for (i = 1; i < 1000; ++i)
		if (!(i % 3) || !(i % 5))
			sum += i;

	printf("%d\n", sum);

	return 0;
}
