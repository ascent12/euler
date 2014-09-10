#include <stdio.h>
#include <math.h>
#include <stdint.h>

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
	uint64_t sum = 0;
	int i;

	for (i = 2; i < 2000000; ++i)
		if (isprime(i))
			sum += i;

	printf("%lld\n", sum);

	return 0;
}
