#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint64_t i = 1;
	int j;

	while (1) {
		int suc = 1;
		for (j = 2; j < 21; ++j)
			if (i % j)
				suc = 0;
		if (suc)
			break;

		++i;
	}

	printf("%lld\n", i);
	return 0;
}
