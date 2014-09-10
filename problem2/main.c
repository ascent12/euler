#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 1;
	int sum = 0;

	while (b < 4000001) {
		b += a;
		a = b - a;

		if (!(b % 2))
			sum += b;
	}

	printf("%d\n", sum);
}
