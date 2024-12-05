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
	// works at campus computer
	result = execve("/bin/ls", args, NULL);
	if (result == -1)
	{
		result = execve("/usr/bin/ls", args, NULL);
		if (result == -1)
			printf("execve failed: %s\n", strerror(errno));
	}
	printf("This will not be executed\n");
	return (0);
}
