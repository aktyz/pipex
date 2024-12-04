# 14.10.2024 - Starting from understanding External Functions I can use - three per day

<i>"2 months later..."</i>

> This project is mostly about ```<unistd.h>``` Library

## <unistd.h> Library

### close (some examples in man 3)
The  close() function shall deallocate the file descriptor indicated by fildes. To deallocate means to make the file descriptor available for return by subsequent calls to open() or other functions that allocate file descriptors. All outstanding record locks owned by the process on the file associated with the file descriptor shall be removed (that is, unlocked). Syntax:<br>
```
	int close(int fildes);
```
Upon successful completion, 0 shall be returned; otherwise, -1 shall be returned and ```errno``` set to indicate the error.

### read (one example in man 3)
Syntax:<br>
```
	ssize_t read(int fildes, void *buf, size_t nbyte);
```
### write
### access
This function answers a question: can  the  user  who  invoked  me read/write/execute  this  file?

> protip: run with flag F_OK checks if the file exists

### dup
### dup2
### execve
Function to run the bash script. It doesn't work on my computer with WSL

### fork
Clue of the project. Creates a spawned process with it's own copy of memory.
### pipe
Syntax:<br>
```
int pipe(int pipefd[2]);
```
This actually creates two working fds, one for read an second for write.
Those fd's can be assigned to any thread in order to communicate between each other.

### unlink
Simply put deleting the file.

## <stdlib.h> Library

### malloc
### free
### exit

## <stdio.h> Library

### perror

## <string.h> Library

### strerror
Syntax:<br>
```
	char *strerror(int errnum);
```
The  ```strerror()```  function  returns:
	a pointer
		to a string
			that describes the error code
				passed in the argument errnum,
possibly using the LC_MESSAGES part of the current locale to select the appropriate language.
(For example, if errnum is EINVAL, the returned description will be "Invalid argument".)  This  string  must not  be  modified  by  the application, but may be modified by a subsequent call to strerror() or strerror_l().  No other library function, including ```perror(3)```, will modify this string.

## <sys/stat.h> Library

### open (some examples in man 3)
Already used, this option should establish a connection between a file and a file descriptor. Syntax:<br>
```
	int	open(const char *path, int oflag, ...);
```
Exclusive flags (only one can be specified in function):
- ```O_EXEC``` - Open for execute only (non-directory files). The result is unspecified  if  this flag is applied to a directory.
- ```O_RDONLY``` - Open for reading only.
- ```O_RDWR``` - Open for reading and writing. The result is undefined if this flag is applied to a FIFO.
- ```O_SEARCH``` - Open directory for search only. The result is unspecified if this  flag  is  applied to a non-directory file.
- ```O_WRONLY``` - Open for writing only.

Inclusive flags (any combination of the followint may be used):
> seriously, type ```man 3 open``` and scroll down
Upon successful completion, these functions shall open the file and return a non-negative integer representing the file descriptor. Otherwise, these functions shall return -1 and set ```errno``` to indicate the error. If -1 is returned, no files shall be created or modified.

## <sys/wait.h> Library

### wait
### waitpid
