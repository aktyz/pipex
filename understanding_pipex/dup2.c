#include <fcntl.h> // open
#include <unistd.h> // dup2, close
#include <stdio.h> //printf

int	main()
{
	int	fd;

	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	//dup2(int oldfd, int newfd);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("This is printed in example.txt\n");
	//I don't know how to stop redirecting - should this be executed by a fork and fork closed after writing to the file?
	return (0);
}
