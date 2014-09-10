#include <stdio.h>
#include <string.h>

int ispalindrome(int n)
{
	char buf[7];
	char *ptr1, *ptr2;

	snprintf(buf, 7, "%d", n);

	ptr1 = buf;
	ptr2 = buf + strlen(buf) - 1;

	while (*ptr1 == *ptr2 && ptr1 < ptr2) {
		++ptr1;
		--ptr2;
	}

	if (*ptr1 == *ptr2)
		return 1;

	return 0;
}

int main(void)
{
	int i, j;
	int biggest = 0;

	for (i = 100; i < 1000; ++i)
		for (j = 100; j < 1000; ++j)
			if (ispalindrome(i * j) && i * j > biggest)
				biggest = i * j;

	printf("%d\n", biggest);
	return 0;
}
