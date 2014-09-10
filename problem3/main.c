#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define NUM_PRIMES 1000000

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
	if (sum == n)
		return primes[i - 1];

	if (sum > n)
		return 0;

	uint64_t ret;

	if(!(ret = primefact(n, i + 1, sum * primes[i])))
		while (!ret && primes[i] < sqrt(n))
			ret = primefact(n, ++i, sum);

	return ret;
}

int main(void)
{
	int i = 1;
	int j = 0;

	while (j < NUM_PRIMES)
		if (isprime(++i))
			primes[j++] = i;

	printf("%d\n", primefact(600851475143, 0, 1));

	return 0;
}
