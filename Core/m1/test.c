#include <stdlib.h>

int main (void)
{
	char *ptr = malloc(5);

	free(ptr);
	// ptr = ptr + 4;
}
