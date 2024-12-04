
#include <stdio.h> //printf
#include <unistd.h> //access

int	main()
{
	if (!access("example.txt", F_OK))
		printf("File exist\n");
	else
		printf("File doesn't exist\n");
	return (0);
}
