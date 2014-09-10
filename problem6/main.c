#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int i;

	for (i = 1; i < 101; ++i)
		a += pow(i, 2);

	for (i = 1; i < 101; ++i)
		b += i;
	b = pow(b, 2);

	printf("%d\n", abs(a - b));
}
