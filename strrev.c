#include "stdlib.h"

void main()
{
	char p[] = "manish";
	char i, j = 0;
	char *first;
	first = (char*) malloc (strlen(p) + 1);

#if 0	
	first = p;
	last = p + strlen(p) - 1;

	while(first < last)
	{
		s	 = *last;
		*last 	 = *first;
		*first   = s;
		first ++;
		last --;

	}
#endif
	for (i = (strlen(p) - 1); i >= 0; i--)
	{
		first[j] = p[i];
		j++;
	}

	first[j] = '\0';
	printf("%s\n", &first[0]);
}
