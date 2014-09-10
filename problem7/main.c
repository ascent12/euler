#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	if (!(n % 2) && n != 2)
		return 0;

	int i;

	for (i = 3; i <= sqrt(n); i += 2)
		if (!(n % i))
			return 0;

	return 1;
}

int main(void)
{
	int i = 1;
	int j = 0;

	while (j < 10001)
		if (isprime(++i))
			++j;

	printf("%d\n", i);
	return 0;
}
