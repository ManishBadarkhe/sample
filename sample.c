#include "stdlib.h"

char *argv[12];

void main()
{
	int pid;
	int status;
	int i;

	argv[0] = "ls";
	argv[1]	= "ps -ef";
	argv[1] = NULL;

	if ((pid = fork()) < 0)
		printf("----fork failed------\n");
	else if (pid == 0) {
		printf("%s\n", argv[0]);
		for (i = 0; i < 2; i++)
		{ 
			if (execvp(*argv, argv) < 0)
				printf("Execution failed\n");
		}
		printf("I am in child\n");
	} else {
		while (wait(&status) != pid) 
		printf("I am in parent\n");
	}
}
