#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define NUM_PRIMES 10000

uint64_t primes[NUM_PRIMES];

int isprime(int n)
{
	if (!(n % 2) && n != 2)
		return 0;

	int i;

	for (i = 3; i < sqrt(n); i += 2)
		if (!(n % i))
			return 0;

	return 1;
}

uint64_t primefact(uint64_t n, int i, uint64_t sum)
{
	printf("i=%d\tprimes[i]=%lld\tsum=%lld\n", i, primes[i], sum);

	int orig = i;

	if (sum == n)
		return primes[i - 1];

	if (sum > n)
		return 0;

	uint64_t ret;

	if(!(ret = primefact(n, i + 1, sum * primes[i]))) {
		printf("i=%d\tprimes[i]=%d\tdid not work\n", i, primes[i]);
		while (!ret && primes[i++] <= (uint64_t)ceil(sqrt(n)))
			ret = primefact(n, i, sum);
	}

	printf("\t\ti=%d\tret=%lld\n", orig, ret);
	return ret;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;

	int n = atoi(argv[1]);

	int i = 1;
	int j = 0;

	printf("Calculating the first %d primes...\n", NUM_PRIMES);
	while (j < NUM_PRIMES)
		if (isprime(++i))
			primes[j++] = i;
	printf("Done\n\n");

	printf("Calulating largest prime factor of %d...\n", n);
	printf("%lld\n", primefact(n, 0, 1));
	printf("Done\n");

	return 0;
}
