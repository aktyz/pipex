#include <stdio.h> // printf perror
#include <unistd.h> // unlink
#include <stdlib.h> // exit
#include <errno.h> // errno
#include <string.h> // library

int	main()
{
	int	result;

	result = unlink("example.txt");
	if (result == 0)
		printf("File successfully deleted\n");
	else
		printf("Error when deleting the file: %s\n", strerror(errno));
	exit(EXIT_SUCCESS);
}
