#include <stdio.h>
#include <math.h>

#define c sqrt(pow(a,2) + pow(b,2))

int main(void)
{
	float a = 1;
	float b = 1;

	while (1) {
		if (a + b + c == 1000 && b < c)
			break;

		if (a + b + c > 1000) {
			++a;
			b = 1;
			continue;
		}

		++b;
	}

	printf("%.0f\n", a * b * c);

	return 0;
}
