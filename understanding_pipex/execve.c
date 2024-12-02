#include <unistd.h> // execve
#include <stdio.h> // printf
#include <errno.h> // errno
#include <string.h> // strerror()

int	main()
{
	char	*args[3];
	int		result;

	args[0] = "ls";
	args[1] = "-la";
	args[2] = (char *)NULL;
	// my execve cannot find the binary :(
	result = execve("usr/bin/ls", args, NULL);
	printf("This will not be executed\n");
	if (result == -1)
		{
			printf("return from execve function: %d\n", result);
			printf("execve failed: %s\n", strerror(errno));
		}
	return (0);
}
