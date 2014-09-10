#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define NUM_PRIMES 1000

uint64_t primes[NUM_PRIMES];

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

uint64_t primefact(uint64_t n)
{
	int i = 0;

	while (n % primes[i++]);

	n /= primes[--i];

	return n == 1 ? primes[i] : primefact(n);
}

int main(void)
{
	int i = 1;
	int j = 0;

	while (j < NUM_PRIMES)
		if (isprime(++i))
			primes[j++] = i;

	printf("%lld\n", primefact(600851475143));

	return 0;
}
