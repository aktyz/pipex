#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> // pid_t

int	main()
{
	int		fd[2];
	pid_t	pid;
	char	buf[13];
	// pipee(fd) tworzy tylko pipe nie określa które procesy będą z niego korzystały
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe
		write(fd[1], "Hello parent!", 13);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buf, 13);
		close(fd[0]);
		printf("Message from my child: \"%s\"\n", buf);
		exit(EXIT_SUCCESS);
	}
}
