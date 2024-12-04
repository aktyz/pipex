
int main ()
{
	int	pid;

	// ft_split()

	pid = fork();
	if (pid == 0)
	{
		//execute first command and save to pipe
	}
	else
	{
		//execute second command and save to output file
	}
	exit(EXIT_SUCCESS);
}