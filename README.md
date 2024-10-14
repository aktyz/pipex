# No idea how to start this one

# 14.10.2024 - Starting from understanding External Functions I can use - three per day

## open (some examples in man 3)
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
## close (some examples in man 3)
The  close() function shall deallocate the file descriptor indicated by fildes. To deallocate means to make the file descriptor available for return by subsequent calls to open() or other functions that allocate file descriptors. All outstanding record locks owned by the process on the file associated with the file descriptor shall be removed (that is, unlocked). Syntax:<br>
```
	int close(int fildes);
```
Upon successful completion, 0 shall be returned; otherwise, -1 shall be returned and ```errno``` set to indicate the error.
## read (one example in man 3)
Syntax:<br>
```
	ssize_t read(int fildes, void *buf, size_t nbyte);
```
## write
## malloc
## free
## perror
## strerror
## access
## dup
## dup2
## execve
## exit
## fork
## pipe
## unlink
## wait
## waitpid