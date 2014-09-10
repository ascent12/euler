#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 2048

void loadfile(int **num, int *total)
{
	int i = 0;
	char *buf, *ptr;
	FILE *fp;
	size_t s;

	fp = fopen("series.txt", "r");
	if (!fp)
		exit(1);

	fseek(fp, 0, SEEK_END);
	s = ftell(fp);
	rewind(fp);

	buf = calloc(1, s + 1);
	if (!buf)
		goto error1;

	if (!fread(buf, s, 1, fp))
		goto error2;

	*num = calloc(sizeof(**num), s);
	if (!*num)
		goto error3;

	ptr = buf;
	while (*ptr) {
		if (*ptr == '\n') {
			++ptr;
			continue;
		}

		(*num)[i++] = *(ptr++) - '0';
	}

	*total = i;
	free(buf);
	fclose(fp);
	return;

error3:
	free(*num);
error2:
	free(buf);
error1:
	fclose(fp);
	exit(1);
}

int main(void)
{
	int *num, total;
	uint64_t biggest = 0;
	int i, j;

	loadfile(&num, &total);

	for (i = 0; i < total - 12; ++i) {
		uint64_t val = 1;

		for (j = 0; j < 13; ++j)
			val *= num[i + j];

		if (val > biggest)
			biggest = val;
	}

	printf("%lld\n", biggest);

	free(num);
	return 0;
}
